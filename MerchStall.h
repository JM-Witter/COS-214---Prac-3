#ifndef MERCHSTALL_H
#define MERCHSTALL_H

#include "EventUnit.h"
#include <iostream>

class MerchStall : public EventUnit {
private:
    int stock;
    bool open;

public:
    MerchStall(string name, int s) : EventUnit(name), stock(s), open(false) {}

    void open() {
        cout << "- Merch Stall: Opening up" << endl;
        open = true;
    }

    void close() {
        cout << "- Merch Stall: Closing" << endl;
        open = false;
    }

    void reportStatus() const {
        cout << "- Merch Stall [" << open << "]: " << stock << " Remaining stock" << endl;
    }

    int capacity() const {
        return 2; // maybe 0?
    }

    ~MerchStall() {}

    // Observer
    // void update (...) {}
};

#endif