#ifndef MERCHSTALL_H
#define MERCHSTALL_H

#include "EventUnit.h"
#include <iostream>

class MerchStall : public EventUnit {
private:
    int stock;
    bool opened;

public:
    MerchStall(string name, int s) : EventUnit(name), stock(s), opened(false) {}

    void open() override {
        cout << "- Merch Stall: Opening up " << unitName << endl;
        opened = true;
    }

    void close() override {
        cout << "- Merch Stall: Closing " << unitName << endl;
        opened = false;
    }

    void reportStatus() const {
        cout << "- Merch Stall [" << (opened ? "Open" : "Closed") << "]: " << stock << " Remaining stock" << endl;
    }

    int getCapacity() const {
        return 2; // maybe 0?
    }

    ~MerchStall() {}

    // Observer
    // void update (...) {}
};

#endif