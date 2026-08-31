#ifndef STAGE_H
#define STAGE_H

#include "EventGroup.h"

class Stage : public EventGroup {
public:
    explicit Stage(const std::string& name) : EventGroup(name), matchPaused(false) {}

    void reportStatus() const override {
        std::cout << groupName << " [match " << (matchPaused ? "paused" : "ready") << "]" << std::endl;
        EventGroup::reportStatus();
    }

protected:
    void onNotice(const EventNotice& notice) override {
        if (notice.type == NoticeType::NetworkPause || notice.type == NoticeType::ScheduleChange) {
            matchPaused = true;
            std::cout << groupName << ": match flow paused for " << notice.message << std::endl;
        } else if (notice.type == NoticeType::Open) {
            matchPaused = false;
        }
    }

private:
    bool matchPaused;
};

#endif
