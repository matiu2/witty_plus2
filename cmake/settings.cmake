# Which DB system are we going to use ?

set(useSqlite true CACHE BOOL "Use Sqlite for the DB, you can only choose one DB type. Sqlite/MySQL/Postgres")
set(usePostgres false CACHE BOOL "Use Postgres for the DB, you can only choose one DB type. Sqlite/MySQL/Postgres")
set(useMysql false CACHE BOOL "Use Mysql for the DB, you can only choose one DB type. Sqlite/MySQL/Postgres")

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

set(DB_INIT_STRING "myapp.db" CACHE STRING "The string to pass to your DB library. See the library documentation")
