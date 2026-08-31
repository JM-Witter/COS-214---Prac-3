#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include "Subject.h"

#include <iostream>

class EventControl : public Subject {
public:
    void issue(const EventNotice& notice) {
        std::cout << "\n[Event Control] " << notice.message << std::endl;
        notify(notice);
    }
};

#endif
