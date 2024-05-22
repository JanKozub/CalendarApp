#ifndef CALENDARAPP_EVENTSLISTDIALOG_H
#define CALENDARAPP_EVENTSLISTDIALOG_H

#include "QDialog"
#include "QVBoxLayout"
#include <QTableWidget>
#include <vector>
#include "../EventTable/EventTable.h"
#include "../CalendarWidget/CalendarWidget.h"
#include "EventService.h"

using namespace std;

class EventsListDialog : public QDialog {
public:
    explicit EventsListDialog(EventService *eventService, const vector<EventService::Event> &events);
};


#endif //CALENDARAPP_EVENTSLISTDIALOG_H
