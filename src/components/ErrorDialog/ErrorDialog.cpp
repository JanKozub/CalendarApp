#include "ErrorDialog.h"
#include "QLabel"
#include "QHBoxLayout"

ErrorDialog::ErrorDialog(const char *message) {
    QLabel label(message);
    QHBoxLayout l;
    l.addWidget(&label);
    setLayout(&l);
    this->exec();
}
