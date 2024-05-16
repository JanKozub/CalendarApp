#include <QApplication>
#include <QGridLayout>
#include <QMainWindow>
#include "CalendarService/CalendarService.h"
#include "CalendarWidget/CalendarWidget.h"
#include "TopBar/TopBar.h"
#include "QFile"
#include "QDir"
#include "Event/Event.h"
#include "EventService/EventService.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    EventService eventService("events.json");
    try {
        QFile file;
        QDir::setCurrent("/Users/jankozub/Documents/CalendarApp/resources");
        file.setFileName("style.qss");
        file.open(QFile::ReadOnly);
        QString stylesheet = QLatin1String(file.readAll());
        app.setStyleSheet(stylesheet);

        eventService.init();
    } catch(runtime_error er) {
        QDialog errorDialog;
        QLabel label("Loading database failed");
        QHBoxLayout l;
        l.addWidget(&label);
        errorDialog.setLayout(&l);
        errorDialog.exec();
        errorDialog.open();
    }

    CalendarService calendarService;
    QWidget mainWindow;
    mainWindow.setWindowTitle("Calendar App");
    mainWindow.setStyleSheet("background-color: #1A191C;");

    QVBoxLayout layout(&mainWindow);
    CalendarWidget calendarWidget(&mainWindow, &eventService);
    TopBar topBar(&calendarService, &eventService, &calendarWidget);
    layout.addLayout(&topBar);
    layout.addWidget(&calendarWidget);
    mainWindow.setLayout(&layout);

    mainWindow.show();
    return QApplication::exec();
}
