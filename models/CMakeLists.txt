project (model)

add_library(models User.cpp)

install(
    FILES 
        User.hpp
    DESTINATION
        "${CMAKE_INSTALL_PREFIX}/include/wittyPlus/models"
)
