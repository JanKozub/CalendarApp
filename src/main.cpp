#include <QApplication>
#include <QGridLayout>
#include <QMainWindow>
#include "CalendarService/CalendarService.h"
#include "CalendarWidget/CalendarWidget.h"
#include "TopBar/TopBar.h"
#include "QFile"
#include "QDir"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFile file;
    QDir::setCurrent("/Users/jankozub/Documents/CalendarApp/src/resources");
    file.setFileName("style.qss");
    file.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(file.readAll());
    app.setStyleSheet(stylesheet);

    CalendarService calendarService;
    QWidget mainWindow;
    mainWindow.setWindowTitle("Calendar App");
    mainWindow.setStyleSheet("background-color: #1A191C;");

    QVBoxLayout layout(&mainWindow);
    TopBar topBar(&mainWindow);
    CalendarWidget calendarWidget(&mainWindow);
    layout.addLayout(&topBar);
    layout.addWidget(&calendarWidget);
    mainWindow.setLayout(&layout);

    mainWindow.show();
    return QApplication::exec();
}
