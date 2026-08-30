#ifndef TEAMSET_H
#define TEAMSET_H

#include "EventUnit.h"
#include <iostream>

class TeamSet : public EventUnit {
private:
    int id;
    bool paused;

public:
    TeamSet(string name, int id) : EventUnit(name), id(id), paused(false) {}

    void open() {
        cout << "- TeamSet " << id << ": Turning on setup" << endl;
    }

    void close() {
        cout << "- TeamSet " << id << ": Switchin off" << endl;
    }

    void reportStatus() const {
        cout << "- TeamSet " << id << ": " << (paused ? "Paused" : "Active") << endl;
    }

    int capacity() const {
        return 5;
    }

    ~TeamSet() {}

    // Observer
    // void update (...) {}
};

#endif