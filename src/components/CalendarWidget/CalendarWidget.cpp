#include "CalendarWidget.h"

const char *daysNames[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

CalendarWidget::CalendarWidget(QWidget *parent, CalendarService *cs, EventService *es)
        : QTableWidget(parent), calendarService(cs), eventService(es) {
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

void CalendarWidget::setLayoutForMonth() {
    tm *displayedDate = calendarService->getDisplayedDate();
    tm *currentDate = calendarService->getCurrentTime();
    int dayCounter = calendarService->getFirstDayOfWeekOfDisplayedMonth() * -1;
    int currentDayOfMonth = currentDate->tm_mday;
    int daysInCurrentMonth = calendarService->getNumberOfDaysInMonth(displayedDate->tm_mon + 1);
    int daysInPrevMonth = calendarService->getNumberOfDaysInMonth(displayedDate->tm_mon);

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
            for (const auto &e: events)
                if (e.getDay() == label && displayedDate->tm_mon == e.getMonth() &&
                    displayedDate->tm_year + 1900 == e.getYear()) {
                    onDayEvents.push_back(e);
                }

            QString buttonLabel = QString::number(label);
            if (!onDayEvents.empty())
                buttonLabel = QString("%1(%2)").arg(QString::number(label)).arg(onDayEvents.size());

            auto *button = new QPushButton(buttonLabel);
            button->setMinimumSize(120, 120);
            button->setDisabled(buttonDisabled);
            button->setCursor(Qt::PointingHandCursor);
            connect(button, &QPushButton::clicked, this,
                    [=]() { CalendarWidget::onButtonClick(label, displayedDate, onDayEvents); });

            if (!onDayEvents.empty() && !buttonDisabled)
                button->setObjectName("event");

            if (currentDayOfMonth == dayCounter && displayedDate->tm_mon == currentDate->tm_mon)
                button->setObjectName("today");

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

void CalendarWidget::onButtonClick(int dayOfMonth, tm *date, const vector<EventService::Event> &events) {
    NewEventDialog dialog(eventService, dayOfMonth, date, true, events);
    setLayoutForMonth();
}