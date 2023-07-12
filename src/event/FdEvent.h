#pragma once

#include <functional>
#include "Event.h"

class FdEvent : public Event {
 public:
  using CallbackFunc = std::function<void(short events)>;
  using Event::Event;
  enum EventTypes {
    kReadEvent = 0x01,
    kWriteEvent = 0x02,
    kExceptEvent = 0x04,
  };
  virtual bool initialize(int fd, short events, Mode mode) = 0;
  virtual void setCallback(CallbackFunc &&cb) = 0;

 public:
  virtual ~FdEvent() {}
};
