#ifndef CALENDARAPP_NEWEVENTDIALOG_H
#define CALENDARAPP_NEWEVENTDIALOG_H

#include "QDialog"
#include "EventService.h"
#include "../CalendarWidget/CalendarWidget.h"

class NewEventDialog : public QDialog {
private:
    EventService *eventService;
    void createNewEvent(const QDate &date, const QString &msg, const QString &priority);
public:
    NewEventDialog(CalendarWidget *calendarWidget, EventService *eventService, int dayOfMonth, tm* date, bool isDisabled, const vector<EventService::Event> &events);
};

#endif //CALENDARAPP_NEWEVENTDIALOG_H