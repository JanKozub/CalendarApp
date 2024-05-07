#include <QApplication>
#include <QGridLayout>
#include <QMainWindow>
#include "CalendarService/CalendarService.h"
#include "CalendarWidget/CalendarWidget.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CalendarService calendarService;
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Calendar App");

    CalendarWidget calendarWidget(&mainWindow);

    mainWindow.setCentralWidget(&calendarWidget);
    mainWindow.resize(calendarWidget.size());
    mainWindow.show();
    return QApplication::exec();
}
