#ifndef LOUNGE_H
#define LOUNGE_H

#include "EventGroup.h"

/**
 * @class Lounge
 * @brief Represents a lounge area containing multiple event components.
 * Lounge is an EventGroup that fulfills the Concrete Composite role in
 * the Composite design pattern.
 */
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
    /** @brief Indicates whether the lounge's services are currently suspended. */
    bool servicesSuspended;
};

#endif
