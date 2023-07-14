#pragma once

#include <unordered_map>


#include "FdEvent.h"

#ifndef DEFAULT_MAX_LOOP_ENTRIES
#define DEFAULT_MAX_LOOP_ENTRIES (256)
#endif

struct EpollFdSharedData;

class EpollLoop : public Loop {
 public:
  explicit EpollLoop();
  virtual ~EpollLoop() override;

 public:
  //! 是否与Loop在同一个线程内
  virtual bool isInLoopThread() override;
  //! Loop是否正在运行
  virtual bool isRunning() const override;

  virtual void runLoop(Mode mode) override;
//Create Fd Event 
  virtual FdEvent *creatFdEvent(const std::string &fdName) override;

 public:
  inline int epollFd() const { return epollFd_; }

  void addFdSharedData(int fd, EpollFdSharedData *fd_data);
  void removeFdSharedData(int fd);
  EpollFdSharedData *queryFdSharedData(int fd) const;

 protected:
  virtual void stopLoop() { keepRunning_ = false; }

 private:
  int  maxLoopEntries_ = DEFAULT_MAX_LOOP_ENTRIES;
  int  epollFd_ = -1;
  bool keepRunning_ = true;

  std::unordered_map<int, EpollFdSharedData *> fdDataMap_;
};
