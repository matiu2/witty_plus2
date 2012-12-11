cmake_minimum_required(VERSION 2.8)

project (witty-plus)

add_definitions(-std=c++11 -Wall -Wextra)

include(cmake/dependencies.cmake)

add_subdirectory(app)
add_subdirectory(widgets)
add_subdirectory(model)

add_executable(wt-basic main.cpp)
target_link_libraries(wt-basic
    ${Boost_LIBRARIES}
    ${Wt_LIBRARIES}
    app
    #widgets
    #models
)
