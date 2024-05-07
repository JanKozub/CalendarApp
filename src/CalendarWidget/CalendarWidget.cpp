#include "CalendarWidget.h"

const char *daysNames[] = {"Poniedziałek", "Wtorek", "Środa", "Czwartek", "Piątek", "Sobota", "Niedziela"};

CalendarWidget::CalendarWidget(QWidget *parent) : QTableWidget(parent) {
    this->setGeometry(50, 50, 500, 300);
    this->setColumnCount(columns);
    this->setRowCount(rows);

    CalendarService calendarService;

    QStringList headers;
    for (int i = 0; i < columns; ++i) {
        headers << QString(daysNames[i]);
    }
    this->setHorizontalHeaderLabels(headers);
    this->setMinimumSize(120*columns,120*rows);

    int currentDayOfMonth = calendarService.getCurrentDayOfMonth();
    int counter = 1 - calendarService.getFirstDayOfMonthDayOfWeek();
    int numberOfDays = calendarService.getNumberOfDaysInMonth(calendarService.getCurrentMonth());

    QHeaderView *verticalHeader = this->verticalHeader();
    verticalHeader->setVisible(false);

    bool buttonDisabled;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            if (counter == 0) counter++;

            int label = counter;
            if (counter < 0) {
                label = numberOfDays + counter;
                buttonDisabled = true;
            } else {
                if (counter > numberOfDays) {
                    label = counter - numberOfDays;
                    buttonDisabled = true;
                } else {
                    buttonDisabled = false;
                }
            }

            auto *button = new QPushButton(QString("%1").arg(label));
            button->setMinimumSize(120, 120);
            button->setDisabled(buttonDisabled);

            if (currentDayOfMonth == counter) {
                QPalette pal = button->palette();
                pal.setColor(QPalette::Button, QColor(Qt::blue));
                button->setAutoFillBackground(true);
                button->setPalette(pal);
                button->update();
            }

            this->setCellWidget(row, col, button);
            counter++;
        }
    }

    this->resizeColumnsToContents();
    this->resizeRowsToContents();
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
