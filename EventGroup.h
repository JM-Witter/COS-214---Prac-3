#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
#include "Observer.h"
#include "Subject.h"

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

/**
 * @class EventGroup
 * @brief Represents a group of event components that can be managed as one unit, forming a tree with the EventComponents.
 *
 * EventGroup implements the Composite pattern by containing multiple
 * EventComponent objects and forwarding operations such as opening,
 * closing, status reporting, and capacity calculation to its children.
 *
 * EventGroup also implements the Observer and Subject interfaces, allowing
 * it to receive notices from other subjects and notify its own observers.
 */
class EventGroup : public EventComponent, public Observer, public Subject {
protected:
    /**
     * @brief Constructs an EventGroup with the specified name.
     * @param name The name of the event group.
     */
    explicit EventGroup(const string& name) : groupName(name) {}

    /**
     * @brief Opens all components contained in the group.
     * Calls open() on every child EventComponent.
     */
    void openChildren() {
        for (vector<unique_ptr<EventComponent> >::iterator it = children.begin(); it != children.end(); ++it) {
            (*it)->open();
        }
    }

    /**
     * @brief Closes all components contained in the group.
     * Calls close() on every child EventComponent.
     */
    void closeChildren() {
        for (vector<unique_ptr<EventComponent> >::iterator it = children.begin(); it != children.end(); ++it) {
            (*it)->close();
        }
    }

    /**
     * @brief Handles a notice received by the group.
     * This function can be overridden by derived EventGroup classes
     * to provide specific notice-handling behaviour.
     * @param notice The event notice received by the group.
     */
    virtual void onNotice(const EventNotice&) {}

    /** @brief The name of the event group. */
    string groupName;

    /**
     * @brief The collection of components contained in this group..
     */
    vector<unique_ptr<EventComponent> > children;

public:
    /**
     * @brief Adds a component to the group.
     * The group takes ownership of the supplied component.
     * @param child The component to add to the group.
     */
    void add(unique_ptr<EventComponent> child) {
        if (child) {
            children.push_back(move(child));
        }
    }

    /**
     * @brief Removes a component from the group.
     * The ownership of the removed component is returned to the caller.
     * @param child Pointer to the component to remove.
     * @return A unique_ptr containing the removed component, or an empty
     *         unique_ptr if the component was not found.
     */
    unique_ptr<EventComponent> remove(EventComponent* child) {
        for (vector<unique_ptr<EventComponent> >::iterator it = children.begin(); it != children.end(); ++it) {
            if (it->get() == child) {
                unique_ptr<EventComponent> removed = move(*it);
                children.erase(it);
                return removed;
            }
        }
        return unique_ptr<EventComponent>();
    }

    /**
     * @brief Subscribes the group to a subject.
     * The group will receive notices issued by the specified subject.
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
     * @brief Unsubscribes the group from a subject.
     * @param subject The subject to unsubscribe from.
     */
    void unsubscribeFrom(Subject& subject) {
        subject.detach(this);
        subscriptions.erase(remove(subscriptions.begin(), subscriptions.end(), &subject), subscriptions.end());
    }

    /**
     * @brief Opens the event group and all of its children.
     * Displays an opening message and opens each contained component.
     */
    void open() override {
        cout << groupName << ": opening area" << endl;
        openChildren();
    }

    /**
     * @brief Closes the event group and all of its children.
     * Displays a closing message and closes each contained component.
     */
    void close() override {
        cout << groupName << ": closing area" << endl;
        closeChildren();
    }

    /**
     * @brief Reports the status of the group and its children.
     * Displays the number of contained components and requests
     * each child to report its own status.
     */
    void reportStatus() const override {
        cout << groupName << ": " << children.size() << " contained components" << endl;
        for (vector<unique_ptr<EventComponent> >::const_iterator it = children.begin(); it != children.end(); ++it) {
            (*it)->reportStatus();
        }
    }

    /**
     * @brief Calculates the total capacity of the group.
     * @return The total capacity of all child components.
     */
    int getCapacity() const override {
        int total = 0;
        for (vector<unique_ptr<EventComponent> >::const_iterator it = children.begin(); it != children.end(); ++it) {
            total += (*it)->getCapacity();
        }
        return total;
    }

    /**
     * @brief Receives a notice and forwards it to observers.
     * @param notice The event notice being received.
     */
    void update(const EventNotice& notice) override {
        onNotice(notice);
        notify(notice);
    }

    /**
     * @brief Destroys the EventGroup and removes its subscriptions.
     */
    ~EventGroup() override { detachAll(); }

private:
    /**
     * @brief Subjects to which this group is currently subscribed.
     */
    vector<Subject*> subscriptions;

    /**
     * @brief Detaches the group from all subscribed subjects.
     * This ensures that the group is no longer registered as an observer
     * when it is destroyed.
     */
    void detachAll() {
        for (vector<Subject*>::iterator it = subscriptions.begin(); it != subscriptions.end(); ++it) {
            (*it)->detach(this);
        }
        subscriptions.clear();
    }
};

#endif
