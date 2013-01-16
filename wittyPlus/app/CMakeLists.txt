project (app)

SET_PROPERTY(SOURCE db.cpp APPEND PROPERTY COMPILE_DEFINITIONS ${DB_COMPILE_DEFINITION})

add_definitions(-fPIC)
add_library(app STATIC App.cpp db.cpp Server.cpp UserSession.cpp)

install(
    FILES 
        App.hpp
        Server.hpp
        UserSession.hpp
        db.hpp
    DESTINATION
        "${CMAKE_INSTALL_PREFIX}/include/wittyPlus"
)
        
      
