#ifndef SPECTATORBENCH_H
#define SPECTATORBENCH_H

#include "EventUnit.h"

#include <iostream>

/**
 * @class SpectatorBench
 * @brief Represents a seating area for spectators at an event.
 * SpectatorBench is an EventUnit that manages spectator seating,
 * including its maximum capacity and the current number of seated
 * spectators.
 */
class SpectatorBench : public EventUnit {
public:
    SpectatorBench(const std::string& name, int maxCapacity)
        : EventUnit(name), capacity(maxCapacity), seated(0), available(false) {}

    void open() override { available = true; std::cout << "- Spectator Bench (" << unitName << "): available" << std::endl; }
    void close() override { available = false; std::cout << "- Spectator Bench (" << unitName << "): closed" << std::endl; }
    void reportStatus() const override {
        std::cout << "- Spectator Bench (" << unitName << "): " << (available ? std::to_string(seated) + " seated" : "closed") << std::endl;
    }
    int getCapacity() const override { return capacity; }

    void addSeated(int number) {
        if (!available) { std::cout << "- Spectator Bench: currently closed" << std::endl; return; }
        if (number < 0 || seated + number > capacity) { std::cout << "- Spectator Bench: not enough space" << std::endl; return; }
        seated += number;
    }

    void update(const EventNotice& notice) override {
        if (notice.type == NoticeType::CapacityAlert && seated >= notice.value) {
            std::cout << "- Spectator Bench (" << unitName << "): capacity threshold reached; entry restricted" << std::endl;
        } else if (notice.type == NoticeType::Evacuate) {
            seated = 0;
            close();
        } else if (notice.type == NoticeType::Open) {
            open();
        }
    }

    ~SpectatorBench() override {}

private:
    /** @brief The maximum number of spectators that can be seated. */
    int capacity;
    /** @brief The current number of spectators seated on the bench. */
    int seated;
    /** @brief Indicates whether the spectator bench is currently available. */
    bool available;
};

#endif
