#include "scheduleNotification.h"

void ScheduleNotification::schedule(){
    ParseSchedule parser;
    FetchSchedule fetcher;
    NotificationAlert notifier;

    while(true){
        cout<<"Checking for live updates..";

        //Get the schedule
        // vetcor<ScheduledGames> data = fetcher.fetchLOLSchedule();

        // //Parse to check the events
        // parser.parseSchedule(data);

        // //create the alert
        // notifier.sendNotifAlert("The next scheduled game alerts");
    }
}