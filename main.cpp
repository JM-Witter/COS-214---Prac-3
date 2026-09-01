#include "EventControl.h"
#include "FoodStall.h"
#include "Lounge.h"
#include "MainVenue.h"
#include "MerchStall.h"
#include "RefTeam.h"
#include "SpectatorBench.h"
#include "Stage.h"
#include "TeamSet.h"

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main() {
    EventControl control;
    unique_ptr<MainVenue> mainVenue(new MainVenue("Main Tournament Venue"));
    unique_ptr<Stage> stage(new Stage("Tournament Stage"));
    unique_ptr<Lounge> lounge(new Lounge("Lounge Area"));
    Stage* stageArea = stage.get();
    Lounge* loungeArea = lounge.get();

    unique_ptr<TeamSet> redOwner(new TeamSet("Red Team Table"));
    unique_ptr<TeamSet> blueOwner(new TeamSet("Blue Team Table"));
    unique_ptr<RefTeam> refereesOwner(new RefTeam("Ref Squad 1", 3));
    unique_ptr<SpectatorBench> stageBenchesOwner(new SpectatorBench("Stage Benches", 50));
    unique_ptr<FoodStall> foodOwner(new FoodStall("General Snacks Stall", vector<string>{"Breadsticks", "Chips", "Water", "Coffee"}));
    unique_ptr<MerchStall> merchOwner(new MerchStall("Tetris Merch Stall", 30));
    unique_ptr<SpectatorBench> loungeBenchesOwner(new SpectatorBench("Lounge Seating", 10));

    TeamSet* red = redOwner.get();
    TeamSet* blue = blueOwner.get();
    RefTeam* referees = refereesOwner.get();
    SpectatorBench* stageBenches = stageBenchesOwner.get();
    FoodStall* food = foodOwner.get();
    MerchStall* merch = merchOwner.get();
    SpectatorBench* loungeBenches = loungeBenchesOwner.get();

    stage->add(move(redOwner));
    stage->add(move(blueOwner));
    stage->add(move(refereesOwner));
    stage->add(move(stageBenchesOwner));
    lounge->add(move(foodOwner));
    lounge->add(move(merchOwner));
    lounge->add(move(loungeBenchesOwner));

    mainVenue->add(unique_ptr<EventComponent>(stage.release()));
    mainVenue->add(unique_ptr<EventComponent>(lounge.release()));

    MainVenue* venue = mainVenue.get();
    venue->subscribeTo(control);
    stageArea->subscribeTo(*venue);
    loungeArea->subscribeTo(*venue);
    red->subscribeTo(*stageArea);
    red->subscribeTo(*stageArea);
    blue->subscribeTo(*stageArea);
    referees->subscribeTo(*stageArea);
    stageBenches->subscribeTo(*stageArea);
    food->subscribeTo(*loungeArea);
    merch->subscribeTo(*loungeArea);
    loungeBenches->subscribeTo(*loungeArea);

    cout << "\nComposite tree built. Total capacity: " << venue->getCapacity() << endl;
    control.issue(EventNotice(NoticeType::Open, "Doors open"));
    stageBenches->addSeated(24);
    loungeBenches->addSeated(3);

    control.issue(EventNotice(NoticeType::NetworkPause, "Tournament network instability"));
    control.issue(EventNotice(NoticeType::CapacityAlert, "Seating capacity warning", 20));

    cout << "\n[Reorganisation] Moving the merch stall from the lounge to the stage." << endl;
    merch->unsubscribeFrom(*loungeArea);
    unique_ptr<EventComponent> relocated = loungeArea->remove(merch);
    stageArea->add(move(relocated));
    merch->subscribeTo(*stageArea);

    cout << "[Registration change] The blue team table unsubscribes from stage notices." << endl;
    blue->unsubscribeFrom(*stageArea);
    control.issue(EventNotice(NoticeType::Evacuate, "Evacuate the venue"));

    venue->reportStatus();
    return 0;
}
