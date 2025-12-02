//fetcher.h
#include <iostream>
//install curl
#define byte win_byte_override
#include <curl/curl.h>
#undef byte
#include "json.hpp"
#include <vector>
#include "ScheduledGames.h"

using namespace std;

class FetchSchedule{
    public:
    vector<ScheduledGames> fetchLOLSchedule(const string token);
};