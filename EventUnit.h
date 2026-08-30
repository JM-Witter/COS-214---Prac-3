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

	string getUnitName() const {
        return unitName;
    }

	virtual ~EventUnit() {}
};

#endif 