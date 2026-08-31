#ifndef REFTEAM_H
#define REFTEAM_H

#include "EventUnit.h"

#include <iostream>

/**
 * @class RefTeam
 * @brief Represents a team of referees responsible for overseeing event matches.
 * RefTeam is an EventUnit that manages a group of referees and tracks
 * whether they are actively overseeing matches or on standby.
 */
class RefTeam : public EventUnit {
public:
    RefTeam(const std::string& name, int refereeCount) : EventUnit(name), numRefs(refereeCount), active(false) {}

    void open() override { active = true; std::cout << "- Referee Team: " << unitName << " is active" << std::endl; }
    void close() override { active = false; std::cout << "- Referee Team: " << unitName << " is on standby" << std::endl; }
    void reportStatus() const override { std::cout << "- Referee Team: " << numRefs << " referees " << (active ? "actively overseeing matches" : "on standby") << std::endl; }
    int getCapacity() const override { return 0; }

    void update(const EventNotice& notice) override {
        if (notice.type == NoticeType::Evacuate) {
            active = true;
            std::cout << "- Referee Team: directing players and spectators to exits" << std::endl;
        } else if (notice.type == NoticeType::Open) {
            open();
        } else if (notice.type == NoticeType::Close) {
            close();
        }
    }

    ~RefTeam() override {}

private:
    /** @brief The number of referees in the team. */
    int numRefs;
    /** @brief Indicates whether the referee team is currently active. */
    bool active;
};

#endif
