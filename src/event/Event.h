#pragma once

#include <string>

class Loop;
class Event {
 public:
  Event(const std::string& name) : name_(name) {}

  enum class Mode { kPersist, kOneshot };

  virtual bool isEnabled() const = 0;
  virtual bool enable() = 0;
  virtual bool disable() = 0;

  virtual Loop* getLoop() const = 0;

  std::string what() const { return name_; }

 public:
  virtual ~Event() {}

 protected:
  std::string name_;
};
