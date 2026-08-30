#ifndef MERCHSTALL_H
#define MERCHSTALL_H

#include "EventUnit.h"
#include <iostream>

class MerchStall : public EventUnit {
private:
    int stock;

public:
    MerchStall(string name, int s) : EventUnit(name), stock(s) {}

    void open() {
        cout << "- MerchStall: Opening up" << endl;
    }

    void close() {
        cout << "- MerchStall: Closing" << endl;
    }

    void reportStatus() const {
        cout << "- MerchStall: " << stock << " Remaining stock" << endl;
    }

    int capacity() const {
        return 0;
    }

    ~MerchStall() {}

    // Observer
    // void update (...) {}
};

#endif