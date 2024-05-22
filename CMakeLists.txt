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

add_executable(CalendarApp
        src/main.cpp
        src/components/CalendarWidget/CalendarWidget.cpp
        src/components/CalendarWidget/CalendarWidget.h
        src/components/TopBar/TopBar.cpp
        src/components/TopBar/TopBar.h
        src/components/NewEventDialog/NewEventDialog.cpp
        src/components/NewEventDialog/NewEventDialog.h
        src/components/ErrorDialog/ErrorDialog.cpp
        src/components/ErrorDialog/ErrorDialog.h
        src/components/EventsListDialog/EventsListDialog.cpp
        src/components/EventsListDialog/EventsListDialog.h
        src/components/EventTable/EventTable.cpp
        src/components/EventTable/EventTable.h
        src/services/CalendarService/CalendarService.cpp
        src/services/CalendarService/CalendarService.h
        src/services/StylesService/StylesService.cpp
        src/services/StylesService/StylesService.h
)

include_directories(${PROJECT_SOURCE_DIR}/include)

target_link_libraries(CalendarApp
        Qt::Core
        Qt::Gui
        Qt::Widgets
        ${PROJECT_SOURCE_DIR}/lib/libEventService.a
)