#ifndef CALENDARAPP_CALENDARWIDGET_H
#define CALENDARAPP_CALENDARWIDGET_H

#include <QTableWidget>
#include <QPushButton>
#include <QHeaderView>
#include <QBoxLayout>
#include "../../services/CalendarService/CalendarService.h"
#include "../NewEventDialog/NewEventDialog.h"
#include "EventService.h"

class CalendarWidget : public QTableWidget {
private:
    int columns = 7;
    int rows = 5;
    CalendarService *calendarService;
    EventService *eventService;
    void onButtonClick(int dayOfMonth, tm* date, const vector<EventService::Event>& events);
public:
    explicit CalendarWidget(QWidget *parent, CalendarService *calendarService, EventService *eventService);
    void setLayoutForMonth();
};


#endif //CALENDARAPP_CALENDARWIDGET_H
