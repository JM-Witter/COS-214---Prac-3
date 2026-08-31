#ifndef SPECTATORBENCH_H
#define SPECTATORBENCH_H

#include "EventUnit.h"
#include <iostream>

class SpectatorBench : public EventUnit {
private:
    int capacity, seated; 
    bool available; // like if its closed off or not

public:
    SpectatorBench(string name, int s) : EventUnit(name), capacity(s), available(false) {}

    void open() override {
        cout << "- Spectator Bench (" << unitName << "): Now available" << endl;
        available = true;
    }

    void close() override {
        cout << "- Spectator Bench (" << unitName << "): Closing" << endl;
        available = true;
    }

    void reportStatus() const {
        if (available) {
            cout << "- Spectator Bench (" << unitName << "): " << seated << " seated spectators" << endl;
        } else {
            cout << "- Spectator Bench (" << unitName << "): currently closed" << endl;
        }
    }

    int getCapacity() const {
        return capacity;
    }

    void addSeated(int n) {
        if (available) {
            if ((seated + n) > capacity) {
                cout << "Not enough space" << endl;
            } else {
                seated += n;
            }
        } else {
            cout << "Spectator bench is currently closed and cannot get spectators" << endl;
        }
    }

    void removeSeated(int n) {
        if (available) {
            if ((seated - n) < 0) {
                seated = 0;
            } else {
                seated -= n;
            }
        } else {
            cout << "Spectator bench is currently closed and cannot get spectators" << endl;
        }
    }

    ~SpectatorBench() {}

    // Observer
    // void update (...) {}
};

#endif