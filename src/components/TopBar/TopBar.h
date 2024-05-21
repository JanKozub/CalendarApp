#ifndef CALENDARAPP_TOPBAR_H
#define CALENDARAPP_TOPBAR_H

#include "QHBoxLayout"
#include "QPushButton"
#include "QLabel"
#include "../../services/CalendarService/CalendarService.h"
#include "../CalendarWidget/CalendarWidget.h"
#include "../../services/EventService/EventService.h"

class TopBar : public QHBoxLayout{
private:
    CalendarService *calendarService;
    EventService *eventService;
    CalendarWidget *calendarWidget;
    void setMonth(int value, QLabel &monthLabel, QLabel &dateLabel);
public:
    explicit TopBar(CalendarService *cs, EventService *es, CalendarWidget *calendarWidget);
};

#endif //CALENDARAPP_TOPBAR_H