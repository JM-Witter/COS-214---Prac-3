#ifndef LOUNGE_H
#define LOUNGE_H

// Concrete Composite

#include "EventGroup.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Lounge : public EventGroup { //, public Observer, public Subject
public:
	Lounge(string g) : EventGroup(g) {};

    void open() override {
        cout << groupName << ": Opening Lounge" << endl;

        for (EventComponent* c : children) {
            c->open();
        }
    }

    void close() override {
        cout << groupName << ": Closing Lounge" << endl;

        for (EventComponent* c : children) {
            c->close();
        }
    }

    void reportStatus() const override{
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

    // Observer update 
    // void update (...) {} 
};

#endif 