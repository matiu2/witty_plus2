project (app)

add_definitions(-fPIC)
add_library(app STATIC App.cpp Server.cpp UserSession.cpp)

install(
    FILES 
        App.hpp
        Server.hpp
        UserSession.hpp
        db.hpp
    DESTINATION
        "${CMAKE_INSTALL_PREFIX}/include/wittyPlus"
)
        
      
