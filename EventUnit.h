#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"
#include "Observer.h"
#include "Subject.h"

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * @class EventUnit
 * @brief Represents a leaf event component that can observe the composites above it.
 */
class EventUnit : public EventComponent, public Observer {
protected:
    /**
     * @brief Constructs an EventUnit with the specified name.
     * @param name The name of the event unit.
     */
    explicit EventUnit(const string& name) : unitName(name) {}

    /** @brief The name of the event unit. */
    string unitName;

public:
    /**
     * @brief Subscribes the unit to a subject.
     * The unit will receive notices from the specified subject.
     * Duplicate subscriptions are prevented.
     * @param subject The subject to subscribe to.
     */
    void subscribeTo(Subject& subject) {
        if (find(subscriptions.begin(), subscriptions.end(), &subject) == subscriptions.end()) {
            subject.attach(this);
            subscriptions.push_back(&subject);
        }
    }

    /**
     * @brief Unsubscribes the unit from a subject.
     * @param subject The subject to unsubscribe from.
     */
    void unsubscribeFrom(Subject& subject) {
        subject.detach(this);
        subscriptions.erase(remove(subscriptions.begin(), subscriptions.end(), &subject), subscriptions.end());
    }

    /**
     * @brief Gets the name of the event unit.
     * @return A constant reference to the unit's name.
     */
    const string& getUnitName() const { return unitName; }
    /**
     * @brief Destroys the EventUnit and removes all subscriptions.
     * Ensures that the unit is detached from every subject it was
     * subscribed to before the object is destroyed.
     */
    virtual ~EventUnit() { detachAll(); }

private:
    /**
     * @brief Stores the subjects to which this unit is subscribed.
     */
    vector<Subject*> subscriptions;

    /**
     * @brief Detaches the unit from all subscribed subjects.
     */
    void detachAll() {
        for (vector<Subject*>::iterator it = subscriptions.begin(); it != subscriptions.end(); ++it) {
            (*it)->detach(this);
        }
        subscriptions.clear();
    }
};

#endif
