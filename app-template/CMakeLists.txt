cmake_minimum_required(VERSION 2.8)

project (<<PROJECT_NAME>>)

ADD_DEFINITIONS(-std=c++0x -Wall -Wextra)

include(cmake/settings.cmake)
include(cmake/dependencies.cmake)

add_subdirectory(config)

set(DB_INIT_STRING "<<DB_INIT_STRING>>" CACHE STRING "The string to pass to your DB library. See the library documentation")

add_executable(<<EXECUTABLE_NAME>> main.cpp)
target_link_libraries(<<EXECUTABLE_NAME>>
    wittyPlus
    ${wtdbosqlite}
    ${WT_LIBRARIES}
    ${DB_LIBRARIES}
    ${Boost_LIBRARIES}
)
