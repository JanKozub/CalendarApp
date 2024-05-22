cmake_minimum_required(VERSION 3.28)
project(EventService)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT "${CMAKE_SOURCE_DIR}/lib/boost_1_85_0")

find_package(Boost REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Could not find Boost libraries")
endif()

add_library(EventService SHARED
        EventService.cpp
        Event.cpp
)

target_include_directories(EventService PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(EventService ${Boost_LIBRARIES})