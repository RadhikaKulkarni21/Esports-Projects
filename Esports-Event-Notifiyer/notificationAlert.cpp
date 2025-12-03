#include "notificationAlert.h"
#include "wintoastlib.h"

static chrono::system_clock::time_point parseTime(const string timeStamp){
    tm time = {};

    stringstream ss(timeStamp);

    ss>>get_time(&time, "%Y-%m-%dT%H:%M:%SZ");

    return chrono::system_clock::from_time_t(mktime(&time));
}

void NotificationAlert::checkUpcomingMatches(const vector<ScheduledGames>& games, int minutesAhead){

    auto current_time = chrono::system_clock::now();

    for(const auto& g : games){
        auto matchTime = parseTime(g.startTime);

        auto diff = chrono::duration_cast<chrono::hours>(matchTime - current_time).count();

        //This is for when game is 15 mins away
        // if (diff > 0 && diff <= minutesAhead) {
        //     string msg = "Upcoming Match: " + g.teamA + " vs " + g.teamB + " (" + to_string(diff) + " minutes from now)";
        //     sendNotifAlert(msg);
        // }

        string msg = "Upcoming Match: " + g.teamA + " vs " + g.teamB + " (" + to_string(diff) + " hours from now)";
        sendNotifAlert(msg);
    }
}

void NotificationAlert::sendNotifAlert(const string notification){
    cout<< "Upcoming game notification: " << notification << endl;
}