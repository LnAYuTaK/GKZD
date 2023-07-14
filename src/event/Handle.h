/**
 * @file Handle.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <functional>
#include <memory>

class EpollLoop;

class Handle {
 public:
  using EventCallback = std::function<void()>;
  using ReadEventCallback = std::function<void(int)>;
  Handle(EpollLoop* loop, int fd);
  ~Handle();
  void handleEvent(int temp);
  void setReadCallback(ReadEventCallback cb) { readCallback_ = std::move(cb); }
  void setWriteCallback(EventCallback cb) { writeCallback_ = std::move(cb); }
  void setCloseCallback(EventCallback cb) { closeCallback_ = std::move(cb); }
  void setErrorCallback(EventCallback cb) { errorCallback_ = std::move(cb); }
  int fd() const { return fd_; }
  int events() const { return events_; }
  // bool isNoneEvent() const { return events_ == FdEvent::kExceptEvent; }
  // bool isWriting() const { return events_ & FdEvent::kWriteEvent; }
  // bool isReading() const { return events_ & FdEvent::kReadEvent; }

  EpollLoop* ownerLoop() { return loop_; }
  // void remove();

 private:
  // void update();

  EpollLoop* loop_;
  const int fd_;
  short events_;
  std::weak_ptr<void> tie_;
  bool tied_;
  bool eventHandling_;
  bool addedToLoop_;
  ReadEventCallback readCallback_;
  EventCallback writeCallback_;
  EventCallback closeCallback_;
  EventCallback errorCallback_;
};
