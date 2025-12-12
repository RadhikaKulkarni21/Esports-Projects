//notifier.h
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
using namespace std;
#include "fetchSchedule.h"

class NotificationAlert{
    public:
    //parsing the upcoming games
    //Default is set to 15 hours as there are no current leagues but this can be altered for hours/minutes/seconds
    void checkUpcomingMatches(const vector<ScheduledGames>& games, int hoursAhead = 15);
    void sendNotifAlert(const string notification);

    //Discord webhook
    void setWeebHookUrl(string webhookURL);

    private:
    string discordURL;
};