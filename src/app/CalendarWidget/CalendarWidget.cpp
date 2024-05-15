#include "CalendarWidget.h"

const char *daysNames[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

CalendarWidget::CalendarWidget(QWidget *parent) : QTableWidget(parent) {
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

void CalendarWidget::setLayoutForMonth(int currentDayOfMonth, int firstDayOfMonthDayOfWeek, int daysInMonth, int prevMonthDays) {
    int dayCounter = firstDayOfMonthDayOfWeek * -1;

    QHeaderView * verticalHeader = this->verticalHeader();
    verticalHeader->setVisible(false);

    bool buttonDisabled;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            if (dayCounter == 0) dayCounter = 1;

            int label;
            if (dayCounter < 0) {
                label = prevMonthDays + dayCounter + 1;
                buttonDisabled = true;
            } else {
                if (dayCounter <= daysInMonth) {
                    label = dayCounter;
                    buttonDisabled = false;
                } else {
                    label = dayCounter - daysInMonth;
                    buttonDisabled = true;
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