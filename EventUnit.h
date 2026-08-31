#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"
#include "Observer.h"
#include "Subject.h"

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class EventUnit : public EventComponent, public Observer {
protected:
    explicit EventUnit(const string& name) : unitName(name) {}
    string unitName;

public:
    void subscribeTo(Subject& subject) {
        if (find(subscriptions.begin(), subscriptions.end(), &subject) == subscriptions.end()) {
            subject.attach(this);
            subscriptions.push_back(&subject);
        }
    }

    void unsubscribeFrom(Subject& subject) {
        subject.detach(this);
        subscriptions.erase(remove(subscriptions.begin(), subscriptions.end(), &subject), subscriptions.end());
    }

    const string& getUnitName() const { return unitName; }
    virtual ~EventUnit() { detachAll(); }

private:
    vector<Subject*> subscriptions;

    void detachAll() {
        for (vector<Subject*>::iterator it = subscriptions.begin(); it != subscriptions.end(); ++it) {
            (*it)->detach(this);
        }
        subscriptions.clear();
    }
};

#endif
