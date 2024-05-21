#ifndef CALENDARAPP_STYLESSERVICE_H
#define CALENDARAPP_STYLESSERVICE_H
#include "QFile"
#include "QDir"
#include "QString"
#include "QApplication"

class StylesService {
public:
    static void setStyleForApp(QApplication *app, const QString& filename);
};


#endif //CALENDARAPP_STYLESSERVICE_H
