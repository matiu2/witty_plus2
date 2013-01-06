cmake_minimum_required(VERSION 2.8)

project (witty-plus)

add_definitions(-std=c++11 -Wall -Wextra)

include(cmake/settings.cmake)
include(cmake/dependencies.cmake)

add_subdirectory(app)
add_subdirectory(widgets)
add_subdirectory(models)
add_subdirectory(app-builder)

add_library(wittyPlus SHARED )
target_link_libraries(wittyPlus
    ${wtdbosqlite}
    ${WT_LIBRARIES}
    ${DB_LIBRARIES}
    ${Boost_LIBRARIES}
    app models
)

install(DIRECTORY app-template
        DESTINATION "${APP_TEMPLATE_INSTALL_DIR}"
        FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DIRECTORY_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)
