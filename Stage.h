#ifndef STAGE_H
#define STAGE_H

// Concrete Composite

#include "EventGroup.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stage : public EventGroup { //, public Observer, public Subject
public:
	Stage(string g) : EventGroup(g) {};

    void open() override {
        cout << groupName << ": Opening Stage" << endl;

        for (EventComponent* c : children) {
            c->open();
        }
    }

    void close() override {
        cout << groupName << ": Closing Stage" << endl;

        for (EventComponent* c : children) {
            c->close();
        }
    }

    void reportStatus() const override {
        cout << groupName << ": " << children.size() << " composites" << endl;

        for (EventComponent* c : children) {
            c->reportStatus();
        }
    }

    int getCapacity() const override {
        int total = 0;

        for (EventComponent* c : children) {
            total += c->getCapacity();
        }

        return total;
    }

	virtual ~Stage() {
        for (EventComponent* c : children) {
            delete c;
        }

        children.clear();
    }

    // Observer update 
    // void update (...) {} 
};

#endif 