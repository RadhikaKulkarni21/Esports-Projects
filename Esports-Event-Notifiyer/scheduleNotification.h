//scheduler.h
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std; 

//Other header files
#include "parseSchedule.h"
#include "fetchSchedule.h"
#include "notificationAlert.h"

class ScheduleNotification{
    public:
    void schedule();
};