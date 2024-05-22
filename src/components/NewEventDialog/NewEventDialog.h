#ifndef CALENDARAPP_NEWEVENTDIALOG_H
#define CALENDARAPP_NEWEVENTDIALOG_H

#include "QDialog"
#include "QLineEdit"
#include "QBoxLayout"
#include "QLabel"
#include "QComboBox"
#include "QPushButton"
#include "QDateEdit"
#include "../../services/EventService/EventService.h"
#include "../EventTable/EventTable.h"

class NewEventDialog : public QDialog {
private:
    EventService *eventService;
    void createNewEvent(const QDate &date, const QString &msg, const QString &priority);
public:
    NewEventDialog(EventService *eventService, int dayOfMonth, tm* date, bool isDisabled, const vector<Event> &events);
};

#endif //CALENDARAPP_NEWEVENTDIALOG_H