cmake_policy(PUSH)

set(CMAKE_IMPORT_FILE_VERSION 1)

set(_IMPORT_PREFIX ${CMAKE_CURRENT_LIST_DIR})
get_filename_component(_IMPORT_PREFIX ${_IMPORT_PREFIX} DIRECTORY)
get_filename_component(_IMPORT_PREFIX ${_IMPORT_PREFIX} DIRECTORY)
get_filename_component(_IMPORT_PREFIX ${_IMPORT_PREFIX} DIRECTORY)

# Create imported target basscpp::basscpp
add_library(basscpp::basscpp STATIC IMPORTED)

set_target_properties(basscpp::basscpp PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "${_IMPORT_PREFIX}/lib/bass.lib"
)

# Load information for each installed configuration.
file(GLOB _cmake_config_files "${CMAKE_CURRENT_LIST_DIR}/basscppConfig-*.cmake")
foreach(_cmake_config_file IN LISTS _cmake_config_files)
  include("${_cmake_config_file}")
endforeach()
unset(_cmake_config_file)
unset(_cmake_config_files)

set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)