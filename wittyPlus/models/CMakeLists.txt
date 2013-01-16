project (model)

add_definitions(-fPIC)
add_library(models STATIC User.cpp)

install(
    FILES 
        User.hpp
    DESTINATION
        "${CMAKE_INSTALL_PREFIX}/include/wittyPlus/models"
)
