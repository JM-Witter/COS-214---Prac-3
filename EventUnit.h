#ifndef EVENTUNIT_H
#define EVENTUNIT_H

// Leaf

#include "EventComponent.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class EventUnit : public EventComponent {
protected:
    string unitName;

public:
	EventUnit(string u) : unitName(u) {};

    void add(EventComponent* c) {
        cout << "Cannot add child to Leaf (EventUnit)" << unitName << endl;
    }

	string getUnitName() const {
        return unitName;
    }

	virtual ~EventUnit() {}
};

#endif 