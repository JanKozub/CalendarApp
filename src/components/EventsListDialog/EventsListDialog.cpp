#include "EventsListDialog.h"

EventsListDialog::EventsListDialog(const vector<Event> &events) {
    QTableWidget tableWidget;
    setWindowTitle("Events");

    tableWidget.setRowCount(events.size());
    tableWidget.setColumnCount(3);
    tableWidget.setHorizontalHeaderLabels({"Date", "Message", "Priority"});

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

        tableWidget.setItem(i, 0, date);
        tableWidget.setItem(i, 1,
                            new QTableWidgetItem(QString::fromStdString(events[i].getMessage())));
        tableWidget.setItem(i, 2, new QTableWidgetItem(priority));
    }

    tableWidget.resizeColumnsToContents();
    tableWidget.resizeRowsToContents();

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(&tableWidget);
    setLayout(layout);

    this->exec();
    this->open();
}
