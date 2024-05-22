#include "EventsListDialog.h"

EventsListDialog::EventsListDialog(EventService *es, const vector<EventService::Event> &events) {
    setWindowTitle("Events");

    EventTable eventTable(this, es, events);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(&eventTable);
    setLayout(layout);

    this->setFixedWidth(600);
    this->exec();
    this->open();
}
