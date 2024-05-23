#include "EventsListDialog.h"
#include "QVBoxLayout"
#include "../EventTable/EventTable.h"

EventsListDialog::EventsListDialog(CalendarWidget *cw, EventService *es, const vector<EventService::Event> &events) {
    setWindowTitle("Events");

    EventTable eventTable(this, cw, es, events);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(&eventTable);
    setLayout(layout);

    this->setFixedWidth(600);
    this->exec();
    this->open();
}
