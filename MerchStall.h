#ifndef MERCHSTALL_H
#define MERCHSTALL_H

#include "EventUnit.h"

#include <iostream>

/**
 * @class MerchStall
 * @brief Represents a merchandise stall at an event.
 * MerchStall is an EventUnit that manages merchandise stock and
 * responds to event notices such as opening, closing, evacuation,
 * and schedule changes.
 */
class MerchStall : public EventUnit {
public:
    MerchStall(const std::string& name, int initialStock) : EventUnit(name), stock(initialStock), opened(false) {}

    void open() override { opened = true; std::cout << "- Merch Stall: opening " << unitName << std::endl; }
    void close() override { opened = false; std::cout << "- Merch Stall: closing " << unitName << std::endl; }
    void reportStatus() const override { std::cout << "- Merch Stall [" << (opened ? "open" : "closed") << "]: " << stock << " items in stock" << std::endl; }
    int getCapacity() const override { return 2; }

    void update(const EventNotice& notice) override {
        if (notice.type == NoticeType::Evacuate) close();
        else if (notice.type == NoticeType::ScheduleChange) std::cout << "- Merch Stall: updating merchandise promotion schedule" << std::endl;
        else if (notice.type == NoticeType::Open) open();
        else if (notice.type == NoticeType::Close) close();
    }

    ~MerchStall() override {}

private:
    /** @brief The number of merchandise items currently in stock. */
    int stock;
    /** @brief Indicates whether the merchandise stall is currently open. */
    bool opened;
};

#endif
