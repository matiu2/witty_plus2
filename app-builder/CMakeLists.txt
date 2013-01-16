project (app-builder)

SET_PROPERTY(SOURCE argParser.cpp PROPERTY COMPILE_DEFINITIONS TEMPLATE_DIR=\"${APP_TEMPLATE_INSTALL_DIR}\" ${DB_COMPILE_DEFINITION} DB_WT_LIB_NAME=\"${DB_WT_LIB_NAME}\")

find_package(Boost COMPONENTS iostreams REQUIRED)

add_executable(appBuilder main.cpp argParser.cpp configurator.cpp)
target_link_libraries(appBuilder ${Boost_LIBRARIES})

install(TARGETS appBuilder
        DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
)
