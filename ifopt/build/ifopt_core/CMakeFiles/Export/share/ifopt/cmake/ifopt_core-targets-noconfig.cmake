#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ifopt::ifopt_core" for configuration ""
set_property(TARGET ifopt::ifopt_core APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(ifopt::ifopt_core PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libifopt_core.so"
  IMPORTED_SONAME_NOCONFIG "libifopt_core.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS ifopt::ifopt_core )
list(APPEND _IMPORT_CHECK_FILES_FOR_ifopt::ifopt_core "${_IMPORT_PREFIX}/lib/libifopt_core.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
