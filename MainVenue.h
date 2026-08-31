#ifndef MAINVENUE_H
#define MAINVENUE_H

// Concrete Composite

#include "EventGroup.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MainVenue : public EventGroup { //, public Observer, public Subject
public:
	MainVenue(string g) : EventGroup(g) {};

    void open() override {
        cout << groupName << ": Opening Main Venue" << endl;

        for (EventComponent* c : children) {
            c->open();
        }
    }

    void close() override {
        cout << groupName << ": Closing Main Venue" << endl;

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

	virtual ~MainVenue() {
        for (EventComponent* c : children) {
            delete c;
        }

        children.clear();
    }

    // Observer update 
    // void update (...) {} 
};

#endif 