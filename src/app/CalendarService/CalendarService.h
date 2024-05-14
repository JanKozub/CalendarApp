#ifndef CALENDARAPP_CALENDARSERVICE_H
#define CALENDARAPP_CALENDARSERVICE_H

#include "iostream"
#include "../CalendarWidget/CalendarWidget.h"

using namespace std;
using namespace chrono;

class CalendarService {
private:
    system_clock::time_point initTimestamp;
    time_t time_now;
    tm* local_time;
    int currentMonth;
    int currentYear;
public:
    CalendarService();
    int getFirstDayOfMonthDayOfWeek();
    int getCurrentDayOfMonth();
    int getNumberOfDaysInMonth(int monthNumber);

    void setCurrentMonth(int month);
    int getCurrentMonth() const;

    void setCurrentYear(int year);
    int getCurrentYear() const;
};


#endif //CALENDARAPP_CALENDARSERVICE_H
