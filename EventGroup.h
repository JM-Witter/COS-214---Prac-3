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

class EventGroup : public EventComponent, public Observer, public Subject {
protected:
    explicit EventGroup(const string& name) : groupName(name) {}

    void openChildren() {
        for (vector<unique_ptr<EventComponent> >::iterator it = children.begin(); it != children.end(); ++it) {
            (*it)->open();
        }
    }

    void closeChildren() {
        for (vector<unique_ptr<EventComponent> >::iterator it = children.begin(); it != children.end(); ++it) {
            (*it)->close();
        }
    }

    virtual void onNotice(const EventNotice&) {}

    string groupName;
    vector<unique_ptr<EventComponent> > children;

public:
    void add(unique_ptr<EventComponent> child) {
        if (child) {
            children.push_back(move(child));
        }
    }

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

    void subscribeTo(Subject& subject) {
        if (find(subscriptions.begin(), subscriptions.end(), &subject) == subscriptions.end()) {
            subject.attach(this);
            subscriptions.push_back(&subject);
        }
    }

    void unsubscribeFrom(Subject& subject) {
        subject.detach(this);
        subscriptions.erase(remove(subscriptions.begin(), subscriptions.end(), &subject), subscriptions.end());
    }

    void open() override {
        cout << groupName << ": opening area" << endl;
        openChildren();
    }

    void close() override {
        cout << groupName << ": closing area" << endl;
        closeChildren();
    }

    void reportStatus() const override {
        cout << groupName << ": " << children.size() << " contained components" << endl;
        for (vector<unique_ptr<EventComponent> >::const_iterator it = children.begin(); it != children.end(); ++it) {
            (*it)->reportStatus();
        }
    }

    int getCapacity() const override {
        int total = 0;
        for (vector<unique_ptr<EventComponent> >::const_iterator it = children.begin(); it != children.end(); ++it) {
            total += (*it)->getCapacity();
        }
        return total;
    }

    void update(const EventNotice& notice) override {
        onNotice(notice);
        notify(notice);
    }

    ~EventGroup() override { detachAll(); }

private:
    vector<Subject*> subscriptions;

    void detachAll() {
        for (vector<Subject*>::iterator it = subscriptions.begin(); it != subscriptions.end(); ++it) {
            (*it)->detach(this);
        }
        subscriptions.clear();
    }
};

#endif
