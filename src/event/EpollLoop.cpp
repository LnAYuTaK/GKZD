#include <sys/epoll.h>
#include <unistd.h>

#include <cstdint>
#include <algorithm>
#include <vector>

#include "Loop.h"
#include "EpollLoop.h"
#include "EPollFdEvent.h"

#include <iostream>

EpollLoop::EpollLoop():epollFd_(epoll_create1(EPOLL_CLOEXEC)) {

}

EpollLoop::~EpollLoop() {
//   cleanupDeferredTasks();
  //CHECK_CLOSE_RESET_FD(epollFd_);
}

bool EpollLoop::isInLoopThread() {
    return false;
}

bool EpollLoop::isRunning() const{
    return false;
}

void EpollLoop::runLoop(Mode mode) {
  if (epollFd_ < 0) return;

  std::vector<struct epoll_event> events;

  events.resize(maxLoopEntries_);

  std::cout << "Loop Befor;"<< std::endl;
  keepRunning_ = (mode == Loop::Mode::kForever);
  do {
    int fds =
        epoll_wait(epollFd_, events.data(), events.size(), 20);

    // beginLoopProcess();

    // handleExpiredTimers();

    for (int i = 0; i < fds; ++i) {
      epoll_event &ev = events.at(i);
      
      EpollFdEvent::OnEventCallback(ev.data.fd, ev.events, ev.data.ptr);
    }

    // handleRunInLoopFunc();
    // handleNextFunc();

    /// If the receiver array size is full, increase its size with 1.5 times.
    if (fds >= maxLoopEntries_) {
      maxLoopEntries_ = (maxLoopEntries_ + maxLoopEntries_ / 2);
      events.resize(maxLoopEntries_);
    }

    // endLoopProcess();

  } while (keepRunning_);

  // runThisAfterLoop();
}

void EpollLoop::addFdSharedData(int fd, EpollFdSharedData *fd_event) {
  fdDataMap_.insert(std::make_pair(fd, fd_event));
}

void EpollLoop::removeFdSharedData(int fd) { fdDataMap_.erase(fd); }

EpollFdSharedData *EpollLoop::queryFdSharedData(int fd) const {
  auto it = fdDataMap_.find(fd);
  if (it != fdDataMap_.end()) return it->second;
  return nullptr;
}

FdEvent *EpollLoop::creatFdEvent(const std::string &fdName) {
  return new EpollFdEvent(this,fdName);
}
