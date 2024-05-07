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
    mainWindow.setGeometry(100, 100, 600, 400);
    mainWindow.setWindowTitle("Resizable Table");

    CalendarWidget calendarWidget(&mainWindow);
    mainWindow.setCentralWidget(&calendarWidget);

    mainWindow.show();
    return QApplication::exec();
}
