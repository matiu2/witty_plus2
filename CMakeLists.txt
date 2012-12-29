cmake_minimum_required(VERSION 2.8)

project (witty-plus)

add_definitions(-std=c++11 -Wall -Wextra)

include(cmake/settings.cmake)
include(cmake/dependencies.cmake)

add_subdirectory(app)
add_subdirectory(widgets)
add_subdirectory(models)
add_subdirectory(config)

add_executable(wt-basic main.cpp)
target_link_libraries(wt-basic
    app
    #widgets
    models
    ${wtdbosqlite}
    ${WT_LIBRARIES}
    ${DB_LIBRARIES}
    ${Boost_LIBRARIES}
)
