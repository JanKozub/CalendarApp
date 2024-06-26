#include "TopBar.h"
#include "../NewEventDialog/NewEventDialog.h"
#include "../EventsListDialog/EventsListDialog.h"

const char *months[] = {"January", "Febuary", "March", "April",
                        "May", "June", "July", "August",
                        "September", "October", "November", "December"};

TopBar::TopBar(CalendarService *cs, EventService *es, CalendarWidget *cw) {
    this->calendarService = cs;
    this->eventService = es;
    this->calendarWidget = cw;

    auto *addEventButton = new QPushButton("Add Event");
    addEventButton->setStyleSheet("background-color: #585859;");
    addEventButton->setFixedWidth(150);
    connect(addEventButton, &QPushButton::clicked, this,
            [=]() {
                NewEventDialog dialog(calendarWidget, eventService, 1, cs->getDisplayedDate(), false,
                                      *new vector<EventService::Event>{});
            });
    this->addWidget(addEventButton);

    auto *showEventsButton = new QPushButton("Show Events");
    showEventsButton->setStyleSheet("background-color: #585859;");
    showEventsButton->setFixedWidth(150);
    connect(showEventsButton, &QPushButton::clicked, this,
            [=]() {
                EventsListDialog eventsListDialog(calendarWidget, eventService, eventService->getEvents());
                connect(&eventsListDialog, &QDialog::destroyed, this,
                        [this]() { calendarWidget->refreshCalendarLayout(); });
            });
    this->addWidget(showEventsButton);

    auto *monthLabel = new QLabel();
    auto *dateLabel = new QLabel();
    this->addStretch(1);
    this->addWidget(monthLabel);

    auto *prevWeek = new QPushButton("<");
    prevWeek->setStyleSheet("background-color: #585859;");
    prevWeek->setFixedWidth(50);
    this->addStretch(1);
    connect(prevWeek, &QPushButton::clicked, this, [=]() { setMonth(-1, *monthLabel, *dateLabel); });
    this->addWidget(prevWeek);

    this->addStretch();
    this->addWidget(dateLabel);

    auto nextWeek = new QPushButton(">");
    nextWeek->setStyleSheet("background-color: #585859;");
    nextWeek->setFixedWidth(50);
    connect(nextWeek, &QPushButton::clicked, this, [=]() { setMonth(1, *monthLabel, *dateLabel); });
    this->addWidget(nextWeek);

    setMonth(0, *monthLabel, *dateLabel);
}

void TopBar::setMonth(int value, QLabel &monthLabel, QLabel &dateLabel) {
    tm *date = calendarService->getDisplayedDate();
    int month = date->tm_mon + value;
    int year = date->tm_year;

    if (month < 0) {
        month = 11;
        year--;
    } else if (month > 11) {
        month = 0;
        year++;
    }
    calendarService->setDisplayedMonth(month);
    calendarService->setDisplayedYear(year);

    int daysInMonth = calendarService->getNumberOfDaysInMonth(month + 1);
    monthLabel.setText(months[month]);
    dateLabel.setText(QString("1-%1.%2.%3").arg(daysInMonth).arg(month + 1).arg(1900 + year));

    calendarWidget->refreshCalendarLayout();
}

