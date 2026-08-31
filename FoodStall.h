#ifndef FOODSTALL_H
#define FOODSTALL_H

#include "EventUnit.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 * @class FoodStall
 * @brief Represents a food stall at an event.
 * FoodStall is an EventUnit that provides food services and maintains
 * a menu of available items.
 */
class FoodStall : public EventUnit {
public:
    FoodStall(const string& name, const vector<string>& items)
        : EventUnit(name), menu(items), opened(false), serviceSuspended(false) {}

    void open() override { opened = true; serviceSuspended = false; cout << "- Food Stall: opening " << unitName << endl; }
    void close() override { opened = false; cout << "- Food Stall: closing " << unitName << endl; }
    void reportStatus() const override {
        cout << "- Food Stall [" << (opened && !serviceSuspended ? "open" : "closed") << "]: " << menu.size() << " menu items" << endl;
    }
    int getCapacity() const override { return 2; }

    void update(const EventNotice& notice) override {
        if (notice.type == NoticeType::Evacuate) { serviceSuspended = true; close(); }
        else if (notice.type == NoticeType::CapacityAlert) cout << "- Food Stall: switching to express queue service" << endl;
        else if (notice.type == NoticeType::Open) open();
        else if (notice.type == NoticeType::Close) close();
    }

    ~FoodStall() override {}

private:
    /** @brief Stores the food and beverage items available at the stall. */
    vector<string> menu;
    /** @brief Indicates whether the food stall is currently open. */
    bool opened;
    /** @brief Indicates whether food service has been temporarily suspended. */
    bool serviceSuspended;
};

#endif
