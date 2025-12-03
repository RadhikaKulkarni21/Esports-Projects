#include "fetchSchedule.h"

using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* buffer) {
    size_t totalSize = size * nmemb;

    buffer->append((char*)contents, totalSize);

    return totalSize;
}

vector<ScheduledGames> FetchSchedule::fetchLOLSchedule(const string token){
    //This function allocates and returns an easy handle
    CURL* curl = curl_easy_init();
    string response;//generate the response after accessing the data
    vector<ScheduledGames> games;

    if(curl){
        //URL can be parsed here: https://developers.pandascore.co/reference/get_lol_matches_upcoming
        const char* url =  "https://api.pandascore.co/lol/matches/upcoming";

        struct curl_slist* headers = NULL;
        string auth = "Authorization: Bearer " + token;
        headers = curl_slist_append(headers, auth.c_str());

        // to tell libcurl how to behave
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);//should return ok if no error
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);

        if(res != CURLE_OK){
            cerr << "Curl Error: "<< curl_easy_strerror(res) << endl;
            return games;
        }
    }

    try{
        auto jsonData = json::parse(response);
        for (const auto& e : jsonData) {
            ScheduledGames m;

            // Pandascore JSON keys
            m.event = e.value("league", json::object()).value("name", "");
            
            auto opponents = e.value("opponents", json::array());
            if (opponents.size() >= 2) {
                m.teamA = opponents[0].value("opponent", json::object()).value("name", "");
                m.teamB = opponents[1].value("opponent", json::object()).value("name", "");
            }

            m.startTime = e.value("begin_at", "");

            games.push_back(m);
        }
    }
    catch(...){
        cerr<< "JSON Parse Error";
    }
    return games;
}
