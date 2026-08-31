#ifndef OBSERVER_H
#define OBSERVER_H

#include "EventNotice.h"

class Observer {
public:
    virtual void update(const EventNotice& notice) = 0;
    virtual ~Observer() {}
};

#endif
