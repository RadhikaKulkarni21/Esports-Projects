#include "notificationAlert.h"

int main(){
    FetchSchedule f;
    NotificationAlert n;

    //Update with new correct APIs
    string token = "SOMETOKEN";
    n.setWeebHookUrl("SOMEAPI");
    auto matches = f.fetchLOLSchedule(token);

    cout << "Games fetched: " << matches.size() << "\n";

    n.checkUpcomingMatches(matches, 43);

    return 0;
}