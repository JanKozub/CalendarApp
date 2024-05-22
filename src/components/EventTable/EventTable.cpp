#include "EventTable.h"

EventTable::EventTable(QWidget *parent, const vector<Event>& events) : QTableWidget(parent) {
    setRowCount(events.size());
    setColumnCount(3);
    setHorizontalHeaderLabels({"Date", "Message", "Priority"});

    for (int i = 0; i < events.size(); ++i) {
        auto *date = new QTableWidgetItem(QString("%1.%2.%3")
                                                  .arg(events[i].getDay())
                                                  .arg(events[i].getMonth())
                                                  .arg(events[i].getYear()));
        QString priority;
        if (events[i].getPriority() == Event::Priority::LOW)
            priority = "Low";
        else if (events[i].getPriority() == Event::Priority::MEDIUM)
            priority = "Medium";
        else
            priority = "High";

        setItem(i, 0, date);
        setItem(i, 1, new QTableWidgetItem(QString::fromStdString(events[i].getMessage())));
        setItem(i, 2, new QTableWidgetItem(priority));
    }

    resizeRowsToContents();
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}