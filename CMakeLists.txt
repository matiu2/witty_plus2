cmake_minimum_required(VERSION 2.8)

project (witty-plus)

add_definitions(-std=c++11 -Wall -Wextra)

include(cmake/settings.cmake)
include(cmake/dependencies.cmake)

include_directories(${CMAKE_SOURCE_DIR}) # so #include <wittyPlus/xxx> works

add_subdirectory(wittyPlus)
add_subdirectory(app-builder)

install(DIRECTORY app-template
        DESTINATION "${SHARED_INSTALL_DIRECTORY}"
        FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DIRECTORY_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)
