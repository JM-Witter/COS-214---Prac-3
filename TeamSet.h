#ifndef TEAMSET_H
#define TEAMSET_H

#include "EventUnit.h"

#include <iostream>

/**
 * @class TeamSet
 * @brief Represents a team-related event unit with power and pause states.
 * TeamSet is an EventUnit that manages the operational state of a team
 * set.
 */
class TeamSet : public EventUnit {
public:
    explicit TeamSet(const std::string& name) : EventUnit(name), powered(false), paused(false) {}

    void open() override { powered = true; paused = false; std::cout << "- Team Set [" << unitName << "]: online" << std::endl; }
    void close() override { powered = false; paused = true; std::cout << "- Team Set [" << unitName << "]: powered down" << std::endl; }
    void reportStatus() const override { std::cout << "- Team Set [" << unitName << "]: " << (powered ? (paused ? "paused" : "active") : "offline") << std::endl; }
    int getCapacity() const override { return 5; }

    void update(const EventNotice& notice) override {
        if (notice.type == NoticeType::NetworkPause || notice.type == NoticeType::ScheduleChange) {
            paused = true;
            std::cout << "- Team Set [" << unitName << "]: paused safely" << std::endl;
        } else if (notice.type == NoticeType::Evacuate) {
            close();
        } else if (notice.type == NoticeType::Open) {
            open();
        }
    }

    ~TeamSet() override {}

private:
    /** @brief Indicates whether the team set is currently powered on. */
    bool powered;
    /** @brief Indicates whether the team set is currently paused. */
    bool paused;
};

#endif
