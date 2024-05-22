#include <QApplication>
#include <QGridLayout>
#include <QMainWindow>
#include "services/CalendarService/CalendarService.h"
#include "components/CalendarWidget/CalendarWidget.h"
#include "components/TopBar/TopBar.h"
#include "components/ErrorDialog/ErrorDialog.h"
#include "services/StylesService/StylesService.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    EventService eventService("events.json");
    try {
        StylesService::setStyleForApp(&app, "style.qss");
        eventService.init();
    } catch (runtime_error er) {
        ErrorDialog errorDialog("Loading database failed");
        errorDialog.open();
    }

    CalendarService calendarService;
    QWidget mainWindow;
    mainWindow.setWindowTitle("Calendar App");
    mainWindow.setStyleSheet("background-color: #1A191C;");

    QVBoxLayout layout(&mainWindow);
    CalendarWidget calendarWidget(&mainWindow, &calendarService, &eventService);
    TopBar topBar(&calendarService, &eventService, &calendarWidget);
    layout.addLayout(&topBar);
    layout.addWidget(&calendarWidget);
    mainWindow.setLayout(&layout);

    mainWindow.show();
    return QApplication::exec();
}
