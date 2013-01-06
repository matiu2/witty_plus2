project (<<PROJECT_NAME>>)

add_subdirectory(config)

set(DB_INIT_STRING "<<DB_INIT_STRING>>" CACHE STRING "The string to pass to your DB library. See the library documentation")

add_executable(<<EXECUTABLE_NAME>> main.cpp configurator.cpp argParser.cpp)
target_link_libraries(<<EXECUTABLE_NAME>>
    wittyPlus
    ${wtdbosqlite}
    ${WT_LIBRARIES}
    ${DB_LIBRARIES}
    ${Boost_LIBRARIES}

