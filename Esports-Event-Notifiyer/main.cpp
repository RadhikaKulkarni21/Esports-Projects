#include "notificationAlert.h"

//notificationAlert - to create the notifications
//scheduleNotification - to send the actual notification
//parseSchedule - top parse the timings on Riot apps
//fetchSchedule - to fetch the data from riot apks

int main(){
    FetchSchedule f;
    NotificationAlert n;

    string token = "EXuHpQew8p2TtueUqLleNrNbLjdASNqQv87CII8vT9ur9qpzgc8";
    auto matches = f.fetchLOLSchedule(token);

    cout << "Games fetched: " << matches.size() << "\n";

    n.checkUpcomingMatches(matches, 15);

    return 0;
}