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
    void checkUpcomingMatches(const vector<ScheduledGames>& games, int minutesAhead = 15);
    void sendNotifAlert(const string notification);

    void setWeebHookUrl(string webhookURL);

    private:
    string discordURL;
};