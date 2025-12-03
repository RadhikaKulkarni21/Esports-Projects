#include "notificationAlert.h"

int main(){
    FetchSchedule f;
    NotificationAlert n;

    //Update with new correct APIs
    string token = "TOKEN";
    n.setWeebHookUrl("WEBHOOK");
    
    auto matches = f.fetchLOLSchedule(token);

    //cout << "Games fetched: " << matches.size() << "\n";

    n.checkUpcomingMatches(matches, 44);

    return 0;
}