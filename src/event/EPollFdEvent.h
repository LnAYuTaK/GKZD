#pragma once

#include <sys/epoll.h>

#include "FdEvent.h"
#include "Handle.h"
class EpollLoop;
struct EpollFdSharedData;

class EpollFdEvent : public FdEvent {
 public:
  explicit EpollFdEvent(EpollLoop *wp_loop, const std::string &name);
  virtual ~EpollFdEvent() override;

 public:
  virtual bool initialize(int fd, short events, Mode mode) override;
  virtual void setCallback(CallbackFunc &&cb) override { cb_ = std::move(cb); }

  virtual bool isEnabled() const override { return is_enabled_; }
  virtual bool enable() override;
  virtual bool disable() override;

  virtual Loop *getLoop() const override;

 public:
  static void OnEventCallback(int fd, uint32_t events, void *obj);

 protected:
  void reloadEpoll();
  void onEvent(short events);
  void unrefFdSharedData();

 private:
  EpollLoop *wpLoop_;
  bool is_stop_after_trigger_ = false;

  int fd_ = -1;
  uint32_t events_ = 0;
  bool is_enabled_ = false;

  std::string name_;
  CallbackFunc cb_;
  EpollFdSharedData *d_ = nullptr;

  Handle *  channel_ = nullptr;

  int cb_level_ = 0;
};
