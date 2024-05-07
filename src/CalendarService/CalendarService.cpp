#include "CalendarService.h"

CalendarService::CalendarService() {
    currentTimestamp = system_clock::now();
    time_now = system_clock::to_time_t(currentTimestamp);
    local_time = localtime(&time_now);
}

system_clock::time_point &CalendarService::getCurrentTimestamp() {
    return currentTimestamp;
}

int CalendarService::getFirstDayOfMonthDayOfWeek() {
    tm* temp_local_time = localtime(&time_now);
    temp_local_time->tm_mday = 1;
    time_t first_day_of_month_time = mktime(temp_local_time);
    tm *first_day_of_month_tm = localtime(&first_day_of_month_time);
    return first_day_of_month_tm->tm_wday;
}

int CalendarService::getCurrentDayOfMonth() {
    return local_time->tm_mday;
}

int CalendarService::getCurrentDayOfWeek() {
    return local_time->tm_wday;
}

int CalendarService::getCurrentMonth() {
    return local_time->tm_mday;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int CalendarService::getNumberOfDaysInMonth(int monthNumber) {
    int currentYear = local_time->tm_year + 1900;

    if (monthNumber == 2) {
        if (isLeapYear(currentYear)) {
            return 29;
        } else {
            return 28;
        }
    } else if (monthNumber == 4 || monthNumber == 6 || monthNumber == 9 || monthNumber == 11) {
        return 30;
    } else {
        return 31;
    }
}
