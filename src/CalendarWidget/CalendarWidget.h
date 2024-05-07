#ifndef CALENDARAPP_CALENDARWIDGET_H
#define CALENDARAPP_CALENDARWIDGET_H

#include <QTableWidget>
#include <QPushButton>
#include <QHeaderView>
#include "../CalendarService/CalendarService.h"

class CalendarWidget : public QTableWidget {
private:
    int columns = 7;
    int rows = 5;
public:
    explicit CalendarWidget(QWidget *parent);
};


#endif //CALENDARAPP_CALENDARWIDGET_H
