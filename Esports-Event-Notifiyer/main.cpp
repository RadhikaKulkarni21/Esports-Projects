#include "notificationAlert.h"

int main(){
    FetchSchedule f;
    NotificationAlert n;

    //Update with Token from PandaScore
    string token = "TOKEN";
    //Update with discord webhook URL
    n.setWeebHookUrl("WEBHOOK");
    
    auto matches = f.fetchLOLSchedule(token);

    //This is set to 44 hours for now as there were no current games 
    n.checkUpcomingMatches(matches, 44);

    return 0;
}