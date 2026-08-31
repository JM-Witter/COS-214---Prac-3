#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

#include <algorithm>
#include <vector>

/**
 * @class Subject
 * @brief Provides the interface and functionality for managing observers.
 *
 * Subject is the Subject participant in the Observer design pattern.
 * It maintains a collection of registered observers and provides
 * operations for attaching, detaching, and notifying them.
 *
 * Observer pointers stored by Subject are non-owning. Subject is
 * responsible for sending notifications but does not manage the
 * lifetime of the Observer objects.
 */

class Subject {
public:
    /**
     * @brief Registers an observer for future event notifications.
     * @param observer Observer to register. Must not be null.
     */
    void attach(Observer* observer) {
        if (observer != 0 && std::find(observers.begin(), observers.end(), observer) == observers.end()) {
            observers.push_back(observer);
        }
    }

    /**
     * @brief Removes an observer from the notification list.
     * @param observer Observer to remove from the notification list.
     */
    void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    /**
     * @brief Sends an event notice to all currently registered observers.
     * @param notice The event notice to send to the observers.
     */
    void notify(const EventNotice& notice) {
        const std::vector<Observer*> snapshot(observers);
        for (std::vector<Observer*>::const_iterator it = snapshot.begin(); it != snapshot.end(); ++it) {
            if (std::find(observers.begin(), observers.end(), *it) != observers.end()) {
                (*it)->update(notice);
            }
        }
    }

    /**
     * @brief Virtual destructor for polymorphic destruction.
     *
     * Subject does not own or delete its registered observers.
     */
    virtual ~Subject() {}

private:
    /**
     * @brief Collection of currently registered observers.
     * These pointers are non-owning. The Subject only uses them to
     * deliver notifications and does not delete the referenced objects.
     */
    std::vector<Observer*> observers;
};

#endif
