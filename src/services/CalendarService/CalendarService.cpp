#include "CalendarService.h"

CalendarService::CalendarService() {
    time_point timestamp = system_clock::now();
    time_t time = system_clock::to_time_t(timestamp);
    tm *localTime = localtime(&time);

    currentTime.tm_mday = localTime->tm_mday;
    currentTime.tm_mon = localTime->tm_mon;
    currentTime.tm_year = localTime->tm_year;

    displayedDate.tm_mday = localTime->tm_mday;
    displayedDate.tm_mon = localTime->tm_mon;
    displayedDate.tm_year = localTime->tm_year;
}

int CalendarService::getFirstDayOfWeekOfDisplayedMonth() const { //Returns 0-6 value(day of week of current date)
    tm time = {};
    time.tm_year = displayedDate.tm_year;
    time.tm_mon = displayedDate.tm_mon;
    time.tm_mday = 1;

    time_t date = mktime(&time);
    tm *dateTm = localtime(&date);

    int day = dateTm->tm_wday;
    return (day == 0) ? 6 : (day - 1);
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int CalendarService::getNumberOfDaysInMonth(int month) const { //Returns number of days in given month(1-12 format)
    if (month == 2) {
        if (isLeapYear(currentTime.tm_year)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

tm* CalendarService::getCurrentTime() {
    return &currentTime;
}

void CalendarService::setDisplayedMonth(int month) {
    displayedDate.tm_mon = month;
}

void CalendarService::setDisplayedYear(int year) {
    displayedDate.tm_year = year;
}

tm* CalendarService::getDisplayedDate() {
    return &displayedDate;
}