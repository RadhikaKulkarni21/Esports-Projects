#include "notificationAlert.h"

static chrono::system_clock::time_point parseTime(const string timeStamp){
    tm time = {};

    stringstream ss(timeStamp);

    ss>>get_time(&time, "%Y-%m-%dT%H:%M:%SZ");

    return chrono::system_clock::from_time_t(mktime(&time));
}

void NotificationAlert::setWeebHookUrl(string webHookUrl){
    discordURL = webHookUrl;
}

void NotificationAlert::checkUpcomingMatches(const vector<ScheduledGames>& games, int hoursAhead){

    auto current_time = chrono::system_clock::now();

    for(const auto& g : games){
        auto matchTime = parseTime(g.startTime);

        auto diff = chrono::duration_cast<chrono::hours>(matchTime - current_time).count();

        //This is for when game time is setup
        if (diff > 0 && diff <= hoursAhead) {
            string msg = "Upcoming Match: " + g.teamA + " vs " + g.teamB + " (" + to_string(diff) + " hours from now)";
            sendNotifAlert(msg);
        }
    }
}

void NotificationAlert::sendNotifAlert(const string notification){
    if(discordURL.empty()){
        cout<<"Setup webhook URL"<<endl;
    }

    CURL* curl = curl_easy_init();
    if (!curl) return;

    string jsonPayload = "{\"content\": \"" + notification + "\"}";

    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, discordURL.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonPayload.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        cerr << "Discord webhook error: "
             << curl_easy_strerror(res) << endl;
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
}