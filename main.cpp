#include "EventComponent.h"
#include "EventGroup.h"
#include "EventUnit.h"

#include "MainVenue.h"
#include "Lounge.h"
#include "Stage.h"

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

    SpectatorBench* ls = new SpectatorBench("Lounge Seating", 10);
    SpectatorBench* sb = new SpectatorBench("Stage Benches", 50);

    EventGroup* mainVenue = new MainVenue("Main Tournament Venue");
    EventGroup* stage = new Stage("Tournament Stage");
    EventGroup* lounge = new Lounge("Lounge Area");

    lounge->add(fs);
    lounge->add(ms);
    lounge->add(ls);

    stage->add(red);
    stage->add(blue);
    stage->add(rf);
    stage->add(sb);

    mainVenue->add(stage);
    mainVenue->add(lounge);

    cout << "Total Capacity: " << mainVenue->getCapacity() << endl;

    mainVenue->open();
    cout << endl << endl;

    ls->addSeated(3);
    sb->addSeated(24);

    mainVenue->reportStatus();
    cout << endl << endl;
    mainVenue->close();

    delete mainVenue;

    return 0;
}