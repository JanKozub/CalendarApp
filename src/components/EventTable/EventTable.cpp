#include "EventTable.h"
#include "QHeaderView"
#include "QPushButton"

EventTable::EventTable(QWidget *parent, CalendarWidget *cw, EventService *es, const vector<EventService::Event> &events)
        : QTableWidget(parent), calendarWidget(cw), eventService(es) {
    setRowCount(static_cast<int>(events.size()));
    setColumnCount(4);
    setHorizontalHeaderLabels({"Date", "Message", "Priority", "Delete"});

    updateTable(events);

    resizeRowsToContents();
    horizontalHeader()->setSectionsClickable(false);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    verticalHeader()->setVisible(false);
}

void EventTable::updateTable(vector<EventService::Event> events) {
    clearContents();

    for (int i = 0; i < events.size(); ++i) {
        auto *date = new QTableWidgetItem(QString("%1.%2.%3")
                                                  .arg(events[i].getDay())
                                                  .arg(events[i].getMonth())
                                                  .arg(events[i].getYear()));
        QString priority;
        if (events[i].getPriority() == EventService::Event::Priority::LOW)
            priority = "Low";
        else if (events[i].getPriority() == EventService::Event::Priority::MEDIUM)
            priority = "Medium";
        else
            priority = "High";

        setItem(i, 0, date);
        setItem(i, 1, new QTableWidgetItem(QString::fromStdString(events[i].getMessage())));
        setItem(i, 2, new QTableWidgetItem(priority));

        auto *button = new QPushButton("Delete");
        connect(button, &QPushButton::clicked, this, [=]() { onDelete(events, events[i]); });
        setCellWidget(i, 3, button);
    }
}

void EventTable::onDelete(vector<EventService::Event> events, EventService::Event event) {
    auto it = std::find_if(events.begin(), events.end(), [&event](const EventService::Event &e) {
        return e.getId() == event.getId();
    });
    if (it != events.end()) events.erase(it);

    eventService->removeEventFromDatabase(std::move(event));
    calendarWidget->refreshCalendarLayout();

    updateTable(events);
}
