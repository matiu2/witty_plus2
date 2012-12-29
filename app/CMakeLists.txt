project (app)

SET_PROPERTY(SOURCE db.cpp APPEND PROPERTY COMPILE_DEFINITIONS ${DB_COMPILE_DEFINITION})

add_library(app App.cpp db.cpp Server.cpp UserSession.cpp)
