cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
include(${CMAKE_CURRENT_SOURCE_DIR}/utils.cmake)

SET(CMAKE_CXX_STANDARD_LIBRARIES "")
project(basscpp VERSION 1.0.0 DESCRIPTION "C++ Wrapper for BassAudio")

option(BUILD_DEV "Build dev executable" ${PROJECT_IS_TOP_LEVEL})

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" )

file(GLOB_RECURSE INCLUDE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp" )

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${INCLUDE_FILES})

#set_target_properties(${PROJECT_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS YES)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

set(BASS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/native)

list(APPEND CMAKE_PREFIX_PATH ${BASS_DIR})

DownloadBass(${BASS_DIR} "BASS_LIB_NAME")

find_path(BASS_AUDIO_H bass.h)
find_library(BASS_AUDIO_LIB bass)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include> 
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    
    $<BUILD_INTERFACE:${BASS_AUDIO_H}>
    $<INSTALL_INTERFACE:include> 
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    
    $<BUILD_INTERFACE:${BASS_AUDIO_LIB}>
    $<INSTALL_INTERFACE:lib> 
)

if(BUILD_DEV)
    add_executable(Test ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
    target_link_libraries(Test ${PROJECT_NAME})
endif()

install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include
)

install(
    FILES ${BASS_AUDIO_H}/bass.h
    DESTINATION include
)

install(
    FILES ${BASS_AUDIO_LIB}
    DESTINATION lib
)

if(WIN32)
    install(
        FILES ${BASS_DIR}/bass.dll
        DESTINATION bin
    )
endif()

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

install(
    FILES ${CMAKE_CURRENT_LIST_DIR}/basscppConfig.cmake
    DESTINATION lib/cmake/${PROJECT_NAME}
)