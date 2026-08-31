#ifndef TEAMSET_H
#define TEAMSET_H

#include "EventUnit.h"
#include <iostream>

class TeamSet : public EventUnit {
private:
    bool paused;

public:
    TeamSet(string name) : EventUnit(name), paused(false) {}

    void open() override {
        cout << "- TeamSet " << ": Turning on setup" << endl;
        paused = false;
    }

    void close() override {
        cout << "- TeamSet " << ": Switchin off" << endl;
        paused = true;
    }

    void reportStatus() const {
        cout << "- TeamSet " << ": " << (paused ? "Paused" : "Active") << endl;
    }

    int getCapacity() const {
        return 5;
    }

    ~TeamSet() {}

    // Observer
    // void update (...) {}
};

#endif