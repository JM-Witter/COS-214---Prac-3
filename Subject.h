#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

#include <algorithm>
#include <vector>

class Subject {
public:
    void attach(Observer* observer) {
        if (observer != 0 && std::find(observers.begin(), observers.end(), observer) == observers.end()) {
            observers.push_back(observer);
        }
    }

    void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(const EventNotice& notice) {
        const std::vector<Observer*> snapshot(observers);
        for (std::vector<Observer*>::const_iterator it = snapshot.begin(); it != snapshot.end(); ++it) {
            if (std::find(observers.begin(), observers.end(), *it) != observers.end()) {
                (*it)->update(notice);
            }
        }
    }

    virtual ~Subject() {}

private:
    std::vector<Observer*> observers;
};

#endif
