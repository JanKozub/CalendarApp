#ifndef CALENDARAPP_ERRORDIALOG_H
#define CALENDARAPP_ERRORDIALOG_H
#include "QDialog"
#include "QLabel"
#include "QHBoxLayout"

class ErrorDialog : public QDialog {
public:
    explicit ErrorDialog(const char* message);
};


#endif //CALENDARAPP_ERRORDIALOG_H