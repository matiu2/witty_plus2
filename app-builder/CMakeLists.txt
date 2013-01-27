project (app-builder)

find_package(Boost COMPONENTS iostreams REQUIRED)

add_executable(appBuilder main.cpp configurator.cpp)
target_link_libraries(appBuilder ${Boost_LIBRARIES})

install(TARGETS appBuilder
        DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
)
