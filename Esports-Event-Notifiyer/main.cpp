#include "notificationAlert.h"

int main(){
    FetchSchedule f;
    NotificationAlert n;

    //Update with Token from PandaScore
    //Currently this is a placeholder as uploading API on github flags public repo
    string token = "TOKEN";
    //Update with discord webhook URL
    //IMPORTANT you need to be a discord server owner 
    n.setWeebHookUrl("WEBHOOK");
    
    auto matches = f.fetchLOLSchedule(token);

    //This is set to hours for now as we have declared hours, we can change it to minutes
    n.checkUpcomingMatches(matches, 44);

    return 0;
}