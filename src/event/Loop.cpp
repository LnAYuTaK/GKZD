#include "Loop.h"

#include "EpollLoop.h"
#include "FdEvent.h"

Loop* Loop::New() { return new EpollLoop; }
