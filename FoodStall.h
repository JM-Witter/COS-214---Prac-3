#ifndef FOODSTALL_H
#define FOODSTALL_H

#include "EventUnit.h"
#include <iostream>

class FoodStall : public EventUnit {
private:
    vector<string> menu;
    bool opened;

public:
    FoodStall(string name, vector<string> m) : EventUnit(name), menu(m), opened(false) {}

    void open() override {
        cout << "- Food Stall: Opening up " << unitName << endl;
        opened = true;
    }

    void close() override {
        cout << "- Food Stall: Closing " << unitName << endl;
        opened = false;
    }

    void reportStatus() const {
        cout << "- Food Stall [" << (opened ? "Open" : "Closed") << "] Menu: ";


        for (string m : menu) {
            cout << m << ", ";
        }

        cout << endl;
    }

    int getCapacity() const {
        return 2; // maybe 0?
    }

    ~FoodStall() {}

    // Observer
    // void update (...) {}
};

#endif