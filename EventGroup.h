#ifndef EVENTGROUP_H
#define EVENTGROUP_H

// Composite

#include "EventComponent.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class EventGroup : public EventComponent { //, public Observer, public Subject
protected:
    string groupName;
    vector<EventComponent*> children;

public:
	EventGroup(string g) : groupName(g) {};

	virtual void add(EventComponent* c) {
        if (!c) {
            return;
        }

        children.push_back(c);

        // Observer stuff
        // attach observer to component
    }

    virtual void remove(EventComponent* c) {
        if (!c) {
            return;
        }

        // Observer stuff
        // detatch observer from component

        for (int i = 0; i < (int) children.size(); i++)
        {
            if (children[i] == c) {
                children.erase(children.begin() + i);

                break;
            }
        }
    }

    void open() {
        cout << groupName << ": Opening area" << endl;

        for (EventComponent* c : children) {
            c->open();
        }
    }

    void close() {
        cout << groupName << ": Closing area" << endl;

        for (EventComponent* c : children) {
            c->open();
        }
    }

    void reportStatus() const {
        cout << groupName << ": " << children.size() << " sub/concrete components" << endl;

        for (EventComponent* c : children) {
            c->reportStatus();
        }
    }

    int getCapacity() const {
        int total = 0;

        for (EventComponent* c : children) {
            total += c->getCapacity();
        }

        return total;
    }

	virtual ~EventGroup() {
        for (EventComponent* c : children) {
            delete c;
        }

        children.clear();
    }

    // Observer update 
    // void update (...) {} 
};

#endif 