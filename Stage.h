#ifndef STAGE_H
#define STAGE_H

#include "EventGroup.h"

/**
 * @class Stage
 * @brief Represents a stage area containing components for event matches.
 * Stage is an EventGroup that manages multiple event components and
 * tracks whether the match flow is currently paused.
 */
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
    /** @brief Indicates whether the match flow on the stage is currently paused. */
    bool matchPaused;
};

#endif
