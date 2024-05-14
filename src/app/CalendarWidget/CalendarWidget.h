#ifndef CALENDARAPP_CALENDARWIDGET_H
#define CALENDARAPP_CALENDARWIDGET_H

#include <QTableWidget>
#include <QPushButton>
#include <QHeaderView>
#include <QBoxLayout>
#include "../CalendarService/CalendarService.h"
#include "../NewEventDialog/NewEventDialog.h"

class CalendarWidget : public QTableWidget {
private:
    int columns = 7;
    int rows = 5;
    static void onButtonClick();
public:
    explicit CalendarWidget(QWidget *parent);
    void setLayoutForMonth(int currentDayOfMonth, int firstDayOfMonthDayOfWeek, int daysInMonth);
};


#endif //CALENDARAPP_CALENDARWIDGET_H
