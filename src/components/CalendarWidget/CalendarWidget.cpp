#include "CalendarWidget.h"

const char *daysNames[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

CalendarWidget::CalendarWidget(QWidget *parent, EventService *es) : QTableWidget(parent), eventService(es) {
    this->setColumnCount(columns);
    this->setRowCount(rows);

    QStringList headers;
    for (int i = 0; i < columns; ++i) {
        headers << QString(daysNames[i]);
    }
    this->setHorizontalHeaderLabels(headers);
    this->setMinimumSize(140 * columns, 140 * rows);

    this->clearContents();
}

void CalendarWidget::setLayoutForMonth(CalendarService *cs) {
    tm *displayedDate = cs->getDisplayedDate();
    tm *currentDate = cs->getCurrentTime();
    int dayCounter = cs->getFirstDayOfWeekOfDisplayedMonth() * -1;
    int currentDayOfMonth = currentDate->tm_mday;
    int daysInCurrentMonth = cs->getNumberOfDaysInMonth(displayedDate->tm_mon + 1);
    int daysInPrevMonth = cs->getNumberOfDaysInMonth(displayedDate->tm_mon);

    QHeaderView *verticalHeader = this->verticalHeader();
    verticalHeader->setVisible(false);

    vector<EventService::Event> events = eventService->getEvents();

    bool buttonDisabled;
    int label;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            if (dayCounter == 0) dayCounter = 1;

            if (dayCounter < 0) {
                label = daysInPrevMonth + dayCounter + 1;
                buttonDisabled = true;
            } else {
                if (dayCounter <= daysInCurrentMonth) {
                    label = dayCounter;
                    buttonDisabled = false;
                } else {
                    label = dayCounter - daysInCurrentMonth;
                    buttonDisabled = true;
                }
            }

            vector<EventService::Event> onDayEvents;
            for (const auto &event: events)
                if (event.getDay() == label) onDayEvents.push_back(event);

            QString buttonLabel = QString::number(label);
            if (!onDayEvents.empty())
                buttonLabel = QString("%1(%2)").arg(QString::number(label)).arg(onDayEvents.size());

            auto *button = new QPushButton(buttonLabel);
            button->setMinimumSize(120, 120);
            button->setDisabled(buttonDisabled);
            button->setCursor(Qt::PointingHandCursor);
            connect(button, &QPushButton::clicked, this,
                    [=]() { CalendarWidget::onButtonClick(label, displayedDate, onDayEvents); });

            if (currentDayOfMonth == dayCounter && displayedDate->tm_mon == currentDate->tm_mon)
                button->setObjectName("today");

            if (!onDayEvents.empty() && !buttonDisabled)
                button->setObjectName("event");

            this->setCellWidget(row, col, button);
            dayCounter++;
        }
    }

    this->resizeColumnsToContents();
    this->resizeRowsToContents();
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->horizontalHeader()->setSectionsClickable(false);
}

void CalendarWidget::onButtonClick(int dayOfMonth, tm *date, vector<EventService::Event> events) {
    NewEventDialog dialog(eventService, dayOfMonth, date, true, events);
}