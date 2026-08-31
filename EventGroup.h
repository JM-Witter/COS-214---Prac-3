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

	void add(EventComponent* c) {
        if (!c) {
            return;
        }

        children.push_back(c);

        // Observer stuff
        // attach observer to component
    }

    void remove(EventComponent* c) {
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
    };

    virtual void open() = 0;
    virtual void close() = 0;

    virtual void reportStatus() const = 0;
    virtual int getCapacity() const = 0;
    
    virtual ~EventGroup() {
        for (EventComponent* c : children) {
            delete c;
        }

        children.clear();
    }

    // Observer update 
    // virtual void update (...) {} 
};

#endif 