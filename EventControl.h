#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include "Subject.h"

#include <iostream>

/**
 * @class EventControl
 * @brief Controls and issues event notices to registered observers.
 */
class EventControl : public Subject {
public:
    /**
     * @brief Issues an event notice and notifies all observers.
     * @param notice The EventNotice containing the event information
     *               to be issued.
     */
    void issue(const EventNotice& notice) {
        std::cout << "\n[Event Control] " << notice.message << std::endl;
        notify(notice);
    }
};

#endif
