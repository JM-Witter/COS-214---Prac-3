#ifndef LOUNGE_H
#define LOUNGE_H

#include "EventGroup.h"

class Lounge : public EventGroup {
public:
    explicit Lounge(const std::string& name) : EventGroup(name), servicesSuspended(false) {}

    void reportStatus() const override {
        std::cout << groupName << " [services " << (servicesSuspended ? "suspended" : "available") << "]" << std::endl;
        EventGroup::reportStatus();
    }

protected:
    void onNotice(const EventNotice& notice) override {
        if (notice.type == NoticeType::Evacuate) {
            servicesSuspended = true;
            std::cout << groupName << ": services suspended for evacuation" << std::endl;
        } else if (notice.type == NoticeType::Open) {
            servicesSuspended = false;
        }
    }

private:
    bool servicesSuspended;
};

#endif
