#ifndef CALENDARAPP_CALENDARSERVICE_H
#define CALENDARAPP_CALENDARSERVICE_H

#include "iostream"

using namespace std;
using namespace chrono;

class CalendarService {
private:
    tm currentTime = {}; //Date from user system clock
    tm displayedDate = {}; //Date that is displayed in app
public:
    CalendarService();
    int getNumberOfDaysInMonth(int month) const;

    tm* getDisplayedDate();
    void setDisplayedMonth(int month);
    void setDisplayedYear(int year);
    int getFirstDayOfWeekOfDisplayedMonth() const;

    tm* getCurrentTime();
};


#endif //CALENDARAPP_CALENDARSERVICE_H
