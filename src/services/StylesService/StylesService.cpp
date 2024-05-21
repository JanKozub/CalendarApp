#include "StylesService.h"

void StylesService::setStyleForApp(QApplication *app, const QString& filename) {
    QFile file;
    QDir::setCurrent("/Users/jankozub/Documents/CalendarApp/resources");

    file.setFileName(filename);
    file.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(file.readAll());
    app->setStyleSheet(stylesheet);
}
