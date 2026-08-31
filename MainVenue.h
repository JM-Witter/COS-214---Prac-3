#ifndef MAINVENUE_H
#define MAINVENUE_H

#include "EventGroup.h"

class MainVenue : public EventGroup {
public:
    explicit MainVenue(const std::string& name) : EventGroup(name), emergencyMode(false) {}

    void reportStatus() const override {
        std::cout << groupName << " [" << (emergencyMode ? "EMERGENCY" : "normal operations") << "]" << std::endl;
        EventGroup::reportStatus();
    }

protected:
    void onNotice(const EventNotice& notice) override {
        if (notice.type == NoticeType::Evacuate) {
            emergencyMode = true;
            std::cout << groupName << ": venue evacuation protocol activated" << std::endl;
        } else if (notice.type == NoticeType::Open || notice.type == NoticeType::Close) {
            emergencyMode = false;
        }
    }

private:
    bool emergencyMode;
};

#endif
