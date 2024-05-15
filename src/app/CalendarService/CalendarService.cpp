#include "CalendarService.h"

CalendarService::CalendarService() {
    initTimestamp = system_clock::now();
    time_now = system_clock::to_time_t(initTimestamp);
    local_time = localtime(&time_now);

    currentMonth = local_time->tm_mon;
    currentYear = 1900 + local_time->tm_year;
}

int CalendarService::getFirstDayOfMonthDayOfWeek() const { //Returns 0-6 value(day of week of current date)
    tm time = {};
    time.tm_year = currentYear - 1900;
    time.tm_mon = currentMonth;
    time.tm_mday = 1;

    time_t date = mktime(&time);
    tm *dateTm = localtime(&date);

    int day = dateTm->tm_wday;
    return (day == 0) ? 6 : (day - 1);
}

int CalendarService::getCurrentDayOfMonth() { //Returns current day of month
    return local_time->tm_mday;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int CalendarService::getNumberOfDaysInMonth(int month) const { //Returns number of days in given month(1-12 format)
    if (month == 2) {
        if (isLeapYear(currentYear)) {
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

void CalendarService::setCurrentMonth(int month) {
    currentMonth = month;
}

int CalendarService::getCurrentMonth() const {
    return currentMonth;
}

void CalendarService::setCurrentYear(int year) {
    currentYear = year;
}

int CalendarService::getCurrentYear() const {
    return currentYear;
}