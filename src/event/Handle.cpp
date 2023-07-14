#include "Handle.h"
#include <sys/epoll.h>
#include <sstream>
#include "EpollLoop.h"
Handle::Handle(EpollLoop* loop, int fd__)
    : loop_(loop),
      fd_(fd__),
      events_(0),
      tied_(false)
{

}

Handle::~Handle() {
  if (loop_->isInLoopThread()) {
  }
}

// void Handle::tie(const std::shared_ptr<void>& obj) {
//   tie_ = obj;
//   tied_ = true;
// }

void Handle::handleEvent(int temp) {
  std::shared_ptr<void> guard;
}

// string Handle::reventsToString() const
// {
//   return eventsToString(fd_, revents_);
// }

// string Handle::eventsToString() const
// {
//   return eventsToString(fd_, events_);
// }
