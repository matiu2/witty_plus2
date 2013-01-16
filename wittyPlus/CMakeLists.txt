project (wittyPlus)

add_subdirectory(app)
add_subdirectory(widgets)
add_subdirectory(models)

add_library(wittyPlus SHARED empty.cpp)
target_link_libraries(wittyPlus 
    ${wtdbosqlite}
    ${WT_LIBRARIES}
    ${DB_LIBRARIES}
    ${Boost_LIBRARIES}
    "-Wl,--whole-archive"
    app models
    "-Wl,--no-whole-archive"
)

install(
    TARGETS
        wittyPlus
    LIBRARY
    DESTINATION
        "${CMAKE_INSTALL_PREFIX}/lib"
)
