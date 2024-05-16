#ifndef CALENDARAPP_TOPBAR_H
#define CALENDARAPP_TOPBAR_H

#include "QHBoxLayout"
#include "QPushButton"
#include "QLabel"
#include "../CalendarService/CalendarService.h"
#include "../CalendarWidget/CalendarWidget.h"

class TopBar : public QHBoxLayout{
private:
    CalendarService *calendarService;
    CalendarWidget *calendarWidget;
    void setMonth(int value, QLabel &monthLabel, QLabel &dateLabel);

public:
    explicit TopBar(CalendarService *cs, CalendarWidget *calendarWidget);
};

#endif //CALENDARAPP_TOPBAR_H