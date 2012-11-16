project (vidanueva)

add_definitions(-std=c++11 -Wall -Wextra)

include(cmake/dependencies.cmake)

add_subdirectory(app)
add_subdirectory(widgets)
add_subdirectory(model)

add_executable(wt-basic main.cpp)
target_link_libraries(wt-basic
    widgets
    models
    ${Boost_LIBRARIES}
)
