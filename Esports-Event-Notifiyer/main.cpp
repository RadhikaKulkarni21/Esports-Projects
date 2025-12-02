#include <iostream>
using namespace std;
#include "fetchSchedule.h"

//notificationAlert - to create the notifications
//scheduleNotification - to send the actual notification
//parseSchedule - top parse the timings on Riot apps
//fetchSchedule - to fetch the data from riot apks

int main(){
    FetchSchedule f;
    string token = "HIDDEN_KEY(ENTER YOUR KEY)";
    auto matches = f.fetchLOLSchedule(token);

    cout << "Games fetched: " << matches.size() << "\n";

    for (const auto& m : matches){
        cout<< m.event<<" | " << m.teamA << " vs " << m.teamB << " at " << m.startTime << endl;
    }

    return 0;
}