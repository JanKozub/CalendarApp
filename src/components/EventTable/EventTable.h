#ifndef CALENDARAPP_EVENTTABLE_H
#define CALENDARAPP_EVENTTABLE_H

#include "QTableWidget"
#include "QHeaderView"
#include "vector"
#include "../../model/Event/Event.h"

using namespace std;

class EventTable : public QTableWidget {
public:
    explicit EventTable(QWidget *parent, const vector<Event>& events);
};

#endif //CALENDARAPP_EVENTTABLE_H