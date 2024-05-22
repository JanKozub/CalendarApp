#ifndef CALENDARAPP_EVENTSLISTDIALOG_H
#define CALENDARAPP_EVENTSLISTDIALOG_H

#include "QDialog"
#include "QVBoxLayout"
#include <QTableWidget>
#include <vector>
#include "../EventTable/EventTable.h"
#include "EventService.h"

using namespace std;

class EventsListDialog : public QDialog {
public:
    explicit EventsListDialog(const vector<EventService::Event> &events);
};


#endif //CALENDARAPP_EVENTSLISTDIALOG_H
