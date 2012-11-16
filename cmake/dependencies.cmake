# Boost
find_package(Boost REQUIRED COMPONENTS system thread signals unit_test_framework filesystem program_options)
include_directories(${Boost_INCLUDE_DIRS})

# Wt
option(DEBUG "Make a debug build" ON)
if(DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
    # Try to use the Wt Debug libraries with a 'd' on the end
    find_library(wt wtd wt)
    find_library(wthttp wthttpd wthttp)
    find_library(wtdbo wtdbod wtdbo)
    find_library(wtdbo wtdbopostgresd wtdbopostgres)
else()
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
    find_library(wt wt)
    find_library(wthttp wthttp)
    find_library(wtdbo wtdbo)
    find_library(wtdbo wtdbopostgres)
endif()
