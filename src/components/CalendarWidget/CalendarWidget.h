#ifndef CALENDARAPP_CALENDARWIDGET_H
#define CALENDARAPP_CALENDARWIDGET_H

#include <QTableWidget>
#include <QPushButton>
#include <QHeaderView>
#include <QBoxLayout>
#include "../../services/CalendarService/CalendarService.h"
#include "../NewEventDialog/NewEventDialog.h"
#include "../../services/EventService/EventService.h"

class CalendarWidget : public QTableWidget {
private:
    int columns = 7;
    int rows = 5;
    EventService *eventService;
    void onButtonClick(int dayOfMonth, tm* date, vector<Event> events);
public:
    explicit CalendarWidget(QWidget *parent, EventService *eventService);
    void setLayoutForMonth(CalendarService *cs);
};


#endif //CALENDARAPP_CALENDARWIDGET_H
