#include "EventsListDialog.h"

EventsListDialog::EventsListDialog(const vector<Event> &events) {
    setWindowTitle("Events");

    EventTable eventTable(this, events);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(&eventTable);
    setLayout(layout);

    this->setFixedWidth(600);
    this->exec();
    this->open();
}
