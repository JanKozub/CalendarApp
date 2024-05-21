#include "ErrorDialog.h"

ErrorDialog::ErrorDialog(const char* message) {
    QLabel label(message);
    QHBoxLayout l;
    l.addWidget(&label);
    setLayout(&l);
    this->exec();
}
