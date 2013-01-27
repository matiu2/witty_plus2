
# Boost
find_package(Boost REQUIRED COMPONENTS system thread signals unit_test_framework filesystem program_options)
include_directories(${Boost_INCLUDE_DIRS})

set(Boost_LIBRARIES ${Boost_FILESYSTEM_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_SIGNALS_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY})

# Wt
option(DEBUG "Make a debug build" ON)
if(DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
    # Try to use the Wt Debug libraries with a 'd' on the end
    find_library(WT NAMES wtd wt)
    find_library(WT_HTTP NAMES wthttpd wthttp)
    find_library(WT_DBO NAMES wtdbod wtdbo)
    find_library(WT_DBO_IMPL NAMES "${DB_WT_LIB_NAME}d" ${DB_WT_LIB_NAME}) # This is like wtdbopostgres or wtdbosqlite
else()
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
    find_library(WT wt)
    find_library(WT_HTTP wthttp)
    find_library(WT_DBO wtdbo)
    find_library(WT_DBO_IMPL ${DB_WT_LIB_NAME})
endif()

if (HAVE_DB_LIB)
    find_library(DB_LIB ${DB_LIB_NAME})
endif()

set(WT_LIBRARIES ${WT} ${WT_HTTP} ${WT_DBO})
set(DB_LIBRARIES ${WT_DBO_IMPL} ${DB_LIB})
