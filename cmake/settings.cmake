# Which DB system are we going to use ?

set(useSqlite ON CACHE BOOL "Use Sqlite for the DB, you can only choose one DB type. Sqlite/MySQL/Postgres")
set(usePostgres OFF CACHE BOOL "Use Postgres for the DB, you can only choose one DB type. Sqlite/MySQL/Postgres")
set(useMysql OFF CACHE BOOL "Use Mysql for the DB, you can only choose one DB type. Sqlite/MySQL/Postgres")

math(EXPR number_of_dbs 0)

if (useSqlite)
    math(EXPR number_of_dbs "${number_of_dbs} + 1")
    set(DB_COMPILE_DEFINITION DB_SQLITE)
    set(DB_WT_LIB_NAME wtdbosqlite3)
    set(DB_LIB_NAME sqlite)
endif()

if (usePostgres)
    math(EXPR number_of_dbs "${number_of_dbs} + 1")
    set(DB_COMPILE_DEFINITION DB_POSTGRES)
    set(DB_WT_LIB_NAME wtdbopostgres)
    set(DB_LIB_NAME "")
endif()

if (useMysql)
    math(EXPR number_of_dbs "${number_of_dbs} + 1")
    set(DB_COMPILE_DEFINITION DB_MYSQL)
    message(FATAL_ERROR "Lib Mysql not supported. Please feel free to add it and submit a patch")
endif()

string(COMPARE NOTEQUAL ${number_of_dbs} 1 have_too_many_dbs)
if (have_too_many_dbs)
    message(FATAL_ERROR "You can only have one of useSqlite / usePostgres / useMysql selected. Use ccmake or something to disable the ones you're not using")
endif()

string(COMPARE NOTEQUAL "${DB_LIB_NAME}" "" HAVE_DB_LIB)

# Default app settings

set(SHARED_INSTALL_DIRECTORY "${CMAKE_INSTALL_PREFIX}/share/wittyPlus" CACHE STRING "Where to install any shared resources for the library")
set(APP_TEMPLATE_INSTALL_DIR "${SHARED_INSTALL_DIRECTORY}/app-template")

set(BINARY_INSTALL_DIRECTORY "${CMAKE_INSTALL_PREFIX}/bin" CACHE STRING "Where to install binaries")

# Default build params
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel" FORCE)
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")

# Settings for configuration and script files
IF( "${CMAKE_BUILD_TYPE}" STREQUAL Release )
  SET(WT_DEBUG false)
  ADD_DEFINITIONS(-DBOOST_DISABLE_ASSERTS)
ELSE()
  SET(WT_DEBUG true)
ENDIF()

