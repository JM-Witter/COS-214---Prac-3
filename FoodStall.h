#ifndef FOODSTALL_H
#define FOODSTALL_H

#include "EventUnit.h"
#include <iostream>

class FoodStall : public EventUnit {
private:
    vector<string> menu;
    bool open;

public:
    FoodStall(string name, vector<string> m) : EventUnit(name), menu(m), open(false) {}

    void open() {
        cout << "- Food Stall: Opening up" << endl;
        open = true;
    }

    void close() {
        cout << "- Food Stall: Closing" << endl;
        open = false;
    }

    void reportStatus() const {
        cout << "- Food Stall [" << open << "] Menu: ";


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