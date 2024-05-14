#include "TopBar.h"

const char *months[] = {"January", "Febuary", "March", "April",
                        "May", "June", "July", "August",
                        "September", "October", "November", "December"};

TopBar::TopBar(CalendarService *calendarService, CalendarWidget *calendarWidget) {
    this->calendarService = calendarService;
    this->calendarWidget = calendarWidget;

    auto *addEventButton = new QPushButton("Add Event");
    addEventButton->setStyleSheet("background-color: #C0C3C3;");
    addEventButton->setFixedWidth(150);
    this->addWidget(addEventButton);

    auto *monthLabel = new QLabel();
    auto *dateLabel = new QLabel();
    this->addStretch(1);
    this->addWidget(monthLabel);

    auto *prevWeek = new QPushButton("<");
    prevWeek->setStyleSheet("background-color: #C0C3C3;");
    prevWeek->setFixedWidth(50);
    this->addStretch(1);
    connect(prevWeek, &QPushButton::clicked, this, [=]() { setMonth(-1, *monthLabel, *dateLabel); });
    this->addWidget(prevWeek);

    this->addStretch();
    this->addWidget(dateLabel);

    auto nextWeek = new QPushButton(">");
    nextWeek->setStyleSheet("background-color: #C0C3C3;");
    nextWeek->setFixedWidth(50);
    connect(nextWeek, &QPushButton::clicked, this, [=]() { setMonth(1, *monthLabel, *dateLabel); });
    this->addWidget(nextWeek);

    setMonth(0, *monthLabel, *dateLabel);
}

void TopBar::setMonth(int value, QLabel &monthLabel, QLabel &dateLabel) {
    int month = calendarService->getCurrentMonth() + value;
    int year = calendarService->getCurrentYear();

    if (month < 0) {
        month = 11;
        year--;
    } else if (month > 11) {
        month = 0;
        year++;
    }
    calendarService->setCurrentMonth(month);
    calendarService->setCurrentYear(year);

    int daysInMonth = calendarService->getNumberOfDaysInMonth(month);
    monthLabel.setText(months[calendarService->getCurrentMonth()]);
    dateLabel.setText(QString("1-%1.%2.%3").arg(daysInMonth).arg(month + 1).arg(year));

    calendarWidget->setLayoutForMonth(calendarService->getCurrentDayOfMonth(), calendarService->getFirstDayOfMonthDayOfWeek(), daysInMonth);
}

