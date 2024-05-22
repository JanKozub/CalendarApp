#ifndef CALENDARAPP_EVENTTABLE_H
#define CALENDARAPP_EVENTTABLE_H

#include "QTableWidget"
#include "QHeaderView"
#include "vector"
#include "EventService.h"
#include "QPushButton"

using namespace std;

class EventTable : public QTableWidget {
private:
    EventService *eventService;
    void updateTable(vector<EventService::Event> events);
    void onDelete(vector<EventService::Event> events, EventService::Event event);
public:
    explicit EventTable(QWidget *parent, EventService *eventService, const vector<EventService::Event>& events);
};

#endif //CALENDARAPP_EVENTTABLE_H