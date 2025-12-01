#include "scheduleNotification.h"

void ScheduleNotification::schedule(){
    ParseSchedule parser;
    FetchSchedule fetcher;
    NotificationAlert notifier;

    while(true){
        cout<<"Checking for live updates..";

        //Get the schedule
        string data = fetcher.fetchSchedule();

        //Parse to check the events
        parser.parseSchedule(data);

        //create the alert
        notifier.sendNotifAlert("The next scheduled game alerts");
    }
}