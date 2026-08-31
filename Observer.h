#ifndef OBSERVER_H
#define OBSERVER_H

#include "EventNotice.h"

/**
 * @class Observer
 * @brief Defines the interface for objects that receive event notices.
 *
 * Observer is the Observer participant in the Observer design pattern.
 * Concrete observer classes implement update() to define how they respond
 * when a Subject issues an EventNotice.
 */

class Observer {
public:
    /**
     * @brief Receives an event notice from a Subject.
     * This operation uses a push-based notification approach because
     * the Subject passes the EventNotice directly to the Observer.
     * @param notice The event notice being sent by the Subject.
     */
    virtual void update(const EventNotice& notice) = 0;
    /**
     * @brief Virtual destructor for polymorphic destruction.
     * Allows concrete Observer objects to be destroyed correctly through
     * an Observer pointer.
     */
    virtual ~Observer() {}
};

#endif
