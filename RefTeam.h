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

    void open() {
        cout << "- Referee Team: Opening up" << endl;
    }

    void close() {
        cout << "- Referee Team: Closing" << endl;
    }

    void reportStatus() const {
        cout << "- Referee Team: " << numRefs << " referees " << (active ? "Active" : "on Standby") << endl;
    }

    int getCapacity() const {
        return 0;
    }

    ~RefTeam() {}

    // Observer
    // void update (...) {}
};

#endif