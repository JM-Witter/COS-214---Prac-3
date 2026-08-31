#include "EventComponent.h"
#include "EventGroup.h"
#include "EventUnit.h"

#include "FoodStall.h"
#include "MerchStall.h"
#include "RefTeam.h"
#include "SpectatorBench.h"
#include "TeamSet.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    TeamSet* red = new TeamSet("Red Team Table");
    TeamSet* blue = new TeamSet("Blue Team Table");
    RefTeam* rf = new RefTeam("Ref Squad 1", 3);

    vector<string> menu;
    menu.push_back("Breadsticks");
    menu.push_back("Chips");
    menu.push_back("Water");
    menu.push_back("Coffee");

    FoodStall* fs = new FoodStall("General Snacks Stall", menu);
    MerchStall* ms = new MerchStall("Tetris Merch Stall", 30);

    EventGroup* mainVenue = new EventGroup("Main Tournament Venue");
    EventGroup* stage = new EventGroup("Tournament Stage");
    EventGroup* lounge = new EventGroup("Lounge Area");

    lounge->add(fs);
    lounge->add(ms);

    stage->add(red);
    stage->add(blue);
    stage->add(rf);

    mainVenue->add(stage);
    mainVenue->add(lounge);

    cout << "Total Capacity: " << mainVenue->getCapacity() << endl;

    mainVenue->open();
    cout << endl << endl;
    mainVenue->reportStatus();
    cout << endl << endl;
    mainVenue->close();

    delete mainVenue;

    return 0;
}