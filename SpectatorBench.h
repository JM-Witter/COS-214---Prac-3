#ifndef SPECTATORBENCH_H
#define SPECTATORBENCH_H

#include "EventUnit.h"
#include <iostream>

class SpectatorBench : public EventUnit {
private:
    int seated; 
    bool available; // like if its closed off or not

public:
    SpectatorBench(string name, int s) : EventUnit(name), seated(s), available(false) {}

    void open() {
        cout << "- Spectator Bench: Now available" << endl;
        available = true;
    }

    void close() {
        cout << "- Spectator Bench: Closing" << endl;
        available = true;
    }

    void reportStatus() const {
        if (available) {
            cout << "- Spectator Bench: " << seated << " seated spectators" << endl;
        } else {
            cout << "- Spectator Bench: currently closed" << endl;
        }
    }

    int capacity() const {
        return 50;
    }

    ~SpectatorBench() {}

    // Observer
    // void update (...) {}
};

#endif