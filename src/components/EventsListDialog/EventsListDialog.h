#ifndef CALENDARAPP_EVENTSLISTDIALOG_H
#define CALENDARAPP_EVENTSLISTDIALOG_H

#include "QDialog"
#include "QVBoxLayout"
#include <QTableWidget>
#include <vector>
#include "../../model/Event/Event.h"

using namespace std;

class EventsListDialog : public QDialog {
public:
    explicit EventsListDialog(const vector<Event>& events);
};


#endif //CALENDARAPP_EVENTSLISTDIALOG_H
