#include "CalendarWidget.h"

const char *daysNames[] = {"Poniedziałek", "Wtorek", "Środa", "Czwartek", "Piątek", "Sobota", "Niedziela"};

CalendarWidget::CalendarWidget(QWidget *parent) : QTableWidget(parent) {
    this->setGeometry(50, 50, 500, 300);
    this->setColumnCount(columns);
    this->setRowCount(rows);

    CalendarService calendarService;

    int currentDayOfMonth = calendarService.getCurrentDayOfMonth();
    int counter = 1 - calendarService.getFirstDayOfMonthDayOfWeek();
    int numberOfDays = calendarService.getNumberOfDaysInMonth(calendarService.getCurrentMonth());

    cout << numberOfDays;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            if (counter == 0) counter++;
            if (counter > numberOfDays) counter = 1;

            int label = counter;
            if (counter < 0) label = numberOfDays + counter;

            auto *button = new QPushButton(QString("%1").arg(label));
            button->setMinimumSize(120, 120);

            if (currentDayOfMonth == counter) {
                QPalette pal = button->palette();
                pal.setColor(QPalette::Button, QColor(Qt::blue));
                button->setAutoFillBackground(true);
                button->setPalette(pal);
                button->update();
            }

            this->setCellWidget(row, col, button);

            this->resizeColumnsToContents();
            this->resizeRowsToContents();

            this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            this->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

            counter++;
        }
    }
}

