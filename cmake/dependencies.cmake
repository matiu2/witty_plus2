# Boost
find_package(Boost REQUIRED COMPONENTS system thread signals unit_test_framework filesystem program_options)
include_directories(${Boost_INCLUDE_DIRS})

set(Boost_LIBRARIES ${Boost_FILESYSTEM_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_SIGNALS_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY})

# Wt
# TODO: Make postgres and other sql modules an option
option(DEBUG "Make a debug build" ON)
if(DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
    # Try to use the Wt Debug libraries with a 'd' on the end
    find_library(wt wtd wt)
    find_library(wthttp wthttpd wthttp)
    find_library(wtdbo wtdbod wtdbo)
    find_library(wtdbopostgres wtdbopostgresd wtdbopostgres)
    message(STATUS "DB_WT_LIB_NAME = ${DB_WT_LIB_NAME}")
    find_library(wtdbo_impl "${DB_WT_LIB_NAME}d" ${DB_WT_LIB_NAME})
else()
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
    find_library(wt wt)
    find_library(wthttp wthttp)
    find_library(wtdbo wtdbo)
    find_library(wtdbo_impl ${DB_WT_LIB_NAME})
endif()

if (HAVE_DB_LIB)
    find_library(db_lib ${DB_LIB_NAME})
endif()

set(WT_LIBRARIES ${wt} ${wthttp} ${wtdbo})
set(DB_LIBRARIES ${wtdbo_impl} ${db_lib})

find_library(SQLITE sqlite)
