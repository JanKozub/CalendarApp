#ifndef CALENDARAPP_EVENTTABLE_H
#define CALENDARAPP_EVENTTABLE_H

#include "QTableWidget"
#include "QHeaderView"
#include "vector"
#include "EventService.h"

using namespace std;

class EventTable : public QTableWidget {
public:
    explicit EventTable(QWidget *parent, const vector<EventService::Event>& events);
};

#endif //CALENDARAPP_EVENTTABLE_H