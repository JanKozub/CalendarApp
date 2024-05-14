#ifndef CALENDARAPP_CALENDARSERVICE_H
#define CALENDARAPP_CALENDARSERVICE_H

#include "iostream"

using namespace std;
using namespace chrono;

class CalendarService {
private:
    system_clock::time_point currentTimestamp;
    time_t time_now;
    tm* local_time;
public:
    CalendarService();
    system_clock::time_point &getCurrentTimestamp();
    int getFirstDayOfMonthDayOfWeek();
    int getCurrentDayOfMonth();
    int getCurrentDayOfWeek();
    int getCurrentMonth();
    int getNumberOfDaysInMonth(int monthNumber);
};


#endif //CALENDARAPP_CALENDARSERVICE_H
