cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
include(${CMAKE_CURRENT_SOURCE_DIR}/utils.cmake)

SET(CMAKE_CXX_STANDARD_LIBRARIES "")
project(basscpp VERSION 1.0.0 DESCRIPTION "C++ Wrapper for BassAudio")

option(INTERNAL_BUILD_DEV "Build dev executable" OFF)
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" )

file(GLOB_RECURSE INCLUDE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp" )

add_library(${PROJECT_NAME} INTERFACE ${INCLUDE_FILES})

#set_target_properties(${PROJECT_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS YES)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

set(BASS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/native)

list(APPEND CMAKE_PREFIX_PATH ${BASS_DIR})

DownloadBass(${BASS_DIR})

find_path(BASS_AUDIO_H bass.h)
find_library(BASS_AUDIO_LIB bass)
target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include> 
)
target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${BASS_AUDIO_H}>
    $<INSTALL_INTERFACE:include> 
)


get_filename_component(BASS_AUDIO_LIB_NAME ${BASS_AUDIO_LIB} NAME)

if(WIN32)
    # set_target_properties(${PROJECT_NAME} PROPERTIES
    #     IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/bassCpp.lib"
    #     IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/bassCpp.dll"
    # )
    set_property(TARGET ${PROJECT_NAME} PROPERTY IMPORTED_LOCATION 
        $<BUILD_INTERFACE:${BASS_DIR}/bass.dll>
        $<INSTALL_INTERFACE:bin/bass.dll>
    )

    install(
        FILES ${BASS_DIR}/bass.dll
        DESTINATION bin
    )
endif()

target_link_libraries(${PROJECT_NAME} 
    INTERFACE
    $<BUILD_INTERFACE:${BASS_AUDIO_LIB}>
    $<INSTALL_INTERFACE:lib/${BASS_AUDIO_LIB_NAME}>
    )

if(INTERNAL_BUILD_DEV)
    add_executable(Test ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
    target_link_libraries(Test ${PROJECT_NAME})
endif()

install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
    DESTINATION include/
)

install(
    FILES ${BASS_AUDIO_H}/bass.h
    DESTINATION include/
)

install(
    FILES ${BASS_AUDIO_LIB}
    DESTINATION lib
)

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(
    EXPORT ${PROJECT_NAME}-targets
    FILE ${PROJECT_NAME}Config.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION lib/cmake/${PROJECT_NAME}
)

set(ReflectionExec "VEngineHeaderGen")
set(Reflection_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)
add_executable(${ReflectionExec} ${Reflection_SOURCES})
target_include_directories(${ReflectionExec}
    PRIVATE
    "$<TARGET_PROPERTY:${PROJECT_NAME},INTERFACE_INCLUDE_DIRECTORIES>"
)

add_custom_target(ReflectHeaders
    COMMAND ${ReflectionExec} -s ${CMAKE_CURRENT_SOURCE_DIR}/include -o ${CMAKE_CURRENT_SOURCE_DIR}/include/generated
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Reflect vengine headers"
    SOURCES ${Reflection_SOURCES}
)

add_dependencies(${PROJECT_NAME} ReflectHeaders)