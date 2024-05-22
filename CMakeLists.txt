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

set(BOOST_ROOT "${CMAKE_SOURCE_DIR}/libs/boost_1_85_0")

find_package(Boost REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Could not find Boost libraries")
endif()

add_executable(CalendarApp
        src/main.cpp
        src/services/CalendarService/CalendarService.cpp
        src/services/CalendarService/CalendarService.h
        src/components/CalendarWidget/CalendarWidget.cpp
        src/components/CalendarWidget/CalendarWidget.h
        src/components/TopBar/TopBar.cpp
        src/components/TopBar/TopBar.h
        src/components/NewEventDialog/NewEventDialog.cpp
        src/components/NewEventDialog/NewEventDialog.h
        src/model/Event/Event.cpp
        src/model/Event/Event.h
        src/services/EventService/EventService.cpp
        src/services/EventService/EventService.h
        resources/json.hpp
        src/components/ErrorDialog/ErrorDialog.cpp
        src/components/ErrorDialog/ErrorDialog.h
        src/services/StylesService/StylesService.cpp
        src/services/StylesService/StylesService.h
        src/components/EventsListDialog/EventsListDialog.cpp
        src/components/EventsListDialog/EventsListDialog.h
        src/components/EventTable/EventTable.cpp
        src/components/EventTable/EventTable.h
)

target_link_libraries(CalendarApp
        Qt::Core
        Qt::Gui
        Qt::Widgets
        ${Boost_LIBRARIES}
)