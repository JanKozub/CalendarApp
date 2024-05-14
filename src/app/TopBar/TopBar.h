#ifndef CALENDARAPP_TOPBAR_H
#define CALENDARAPP_TOPBAR_H

#include "QHBoxLayout"
#include "QPushButton"
#include "QLabel"
#include "../CalendarService/CalendarService.h"

class TopBar : public QHBoxLayout{
private:
    CalendarService calendarService;
    void setMonth(int value, QLabel &monthLabel, QLabel &dateLabel);

public:
    explicit TopBar(CalendarService &calendarService);
};

#endif //CALENDARAPP_TOPBAR_H