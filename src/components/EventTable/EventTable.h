#ifndef CALENDARAPP_EVENTTABLE_H
#define CALENDARAPP_EVENTTABLE_H

#include "EventService.h"
#include "../CalendarWidget/CalendarWidget.h"

using namespace std;

class EventTable : public QTableWidget {
private:
    EventService *eventService;
    CalendarWidget *calendarWidget;

    void updateTable(vector<EventService::Event> events);

    void onDelete(vector<EventService::Event> events, EventService::Event event);

public:
    explicit EventTable(QWidget *parent, CalendarWidget *calendarWidget, EventService *eventService,
                        const vector<EventService::Event> &events);
};

#endif //CALENDARAPP_EVENTTABLE_H