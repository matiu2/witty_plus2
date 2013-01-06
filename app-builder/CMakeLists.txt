project (app-builder)

SET_PROPERTY(SOURCE argParser.cpp PROPERTY COMPILE_DEFINITIONS ${DB_COMPILE_DEFINITION})
SET_PROPERTY(SOURCE configurator.cpp PROPERTY COMPILE_DEFINITIONS TEMPLATE_DIR=\"${APP_TEMPLATE_INSTALL_DIR}\")

find_package(Boost COMPONENTS iostreams REQUIRED)

add_executable(appBuilder main.cpp argParser.cpp configurator.cpp)
target_link_libraries(appBuilder ${Boost_LIBRARIES})
