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

