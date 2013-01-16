# DB Library to use (set when wittyPlus was compiled).
set(DB_WT_LIB_NAME <<DB_WT_LIB_NAME>>)

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
