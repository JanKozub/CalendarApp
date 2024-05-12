cmake_minimum_required(VERSION 3.27)
project(CalendarApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "~/Qt/6.7.0/macos/lib/cmake/Qt6")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(CalendarApp src/main.cpp
        src/CalendarService/CalendarService.cpp
        src/CalendarService/CalendarService.h
        src/CalendarWidget/CalendarWidget.cpp
        src/CalendarWidget/CalendarWidget.h
        src/TopBar/TopBar.cpp
        src/TopBar/TopBar.h)

target_link_libraries(CalendarApp
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

