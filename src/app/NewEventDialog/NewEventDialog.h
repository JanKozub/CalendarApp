#ifndef CALENDARAPP_NEWEVENTDIALOG_H
#define CALENDARAPP_NEWEVENTDIALOG_H

#include "QDialog"
#include "QLineEdit"
#include "QBoxLayout"
#include "QLabel"
#include "QComboBox"
#include "QPushButton"
#include "QGroupBox"
#include "QDateEdit"

class NewEventDialog : public QDialog {
public:
    NewEventDialog(int dayOfMonth, tm* date, bool isDisabled);
};

#endif //CALENDARAPP_NEWEVENTDIALOG_H