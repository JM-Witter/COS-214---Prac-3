#ifndef REFTEAM_H
#define REFTEAM_H

#include "EventUnit.h"
#include <iostream>

class RefTeam : public EventUnit {
private:
    int numRefs; // or ref names, idk
    bool active;

public:
    RefTeam(string name, int n) : EventUnit(name), numRefs(n) {}

    void open() override {
        cout << "- Referee Team: " << unitName << " is now active" << endl;
        active = true;
    }

    void close() override {
        cout << "- Referee Team: " << unitName << " will be on standby" << endl;
        active = false;
    }

    void reportStatus() const {
        cout << "- Referee Team: " << numRefs << " referees " << (active ? "currently Active" : "on Standby") << " in " << unitName << endl;
    }

    int getCapacity() const {
        return 0;
    }

    ~RefTeam() {}

    // Observer
    // void update (...) {}
};

#endif