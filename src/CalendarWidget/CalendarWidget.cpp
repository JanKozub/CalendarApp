#include "CalendarWidget.h"

const char *daysNames[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

CalendarWidget::CalendarWidget(QWidget *parent) : QTableWidget(parent) {
    this->setColumnCount(columns);
    this->setRowCount(rows);

    CalendarService calendarService;

    QStringList headers;
    for (int i = 0; i < columns; ++i) {
        headers << QString(daysNames[i]);
    }
    this->setHorizontalHeaderLabels(headers);
    this->setMinimumSize(140 * columns, 140 * rows);

    int currentDayOfMonth = calendarService.getCurrentDayOfMonth();
    int dayCounter = 1 - calendarService.getFirstDayOfMonthDayOfWeek();
    int numberOfDays = calendarService.getNumberOfDaysInMonth(calendarService.getCurrentMonth());

    QHeaderView * verticalHeader = this->verticalHeader();
    verticalHeader->setVisible(false);

    bool buttonDisabled;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            if (dayCounter == 0) dayCounter++;

            int label = dayCounter;
            if (dayCounter < 0) {
                label = numberOfDays + dayCounter;
                buttonDisabled = true;
            } else {
                if (dayCounter > numberOfDays) {
                    label = dayCounter - numberOfDays;
                    buttonDisabled = true;
                } else {
                    buttonDisabled = false;
                }
            }

            auto *button = new QPushButton(QString("%1").arg(label));
            button->setMinimumSize(120, 120);
            button->setDisabled(buttonDisabled);
            button->setCursor(Qt::PointingHandCursor);
            connect(button, &QPushButton::clicked, this, &CalendarWidget::onButtonClick);

            if (currentDayOfMonth == dayCounter) {
                button->setObjectName("today");
            }

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

void CalendarWidget::onButtonClick() {
   NewEventDialog dialog;
}