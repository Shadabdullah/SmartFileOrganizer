cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_STANDARD_DEFAULT 99)
set(CMAKE_C_STANDARD_REQUIRED 99)

project(SmartFileOrganizer)

find_package(SndFile)
find_package(LibArchive REQUIRED)

file(GLOB_RECURSE SOURCE_DIRS LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/src/*")
file(GLOB_RECURSE INCLUDE_DIRS LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/include/*")

set(INCLUDES "")
set(SOURCES "")

foreach(ITEM ${SOURCE_DIRS})
    if(NOT IS_DIRECTORY ${ITEM})
        list(APPEND SOURCES ${ITEM})
    endif()
endforeach()

foreach(ITEM ${INCLUDE_DIRS})
    if(IS_DIRECTORY ${ITEM})
        list(APPEND INCLUDES ${ITEM})
    endif()
endforeach()

list(APPEND INCLUDES "${CMAKE_SOURCE_DIR}/include/")

message(STATUS "Sources found: ${SOURCES}")
message(STATUS "Include directories found: ${INCLUDES}")

include_directories(${INCLUDES})

add_library(cpp_utils STATIC src/cpp/utils.cpp)

#Main target
add_executable(sfo ${SOURCES})
target_link_libraries(sfo PRIVATE cpp_utils SndFile::sndfile LibArchive::LibArchive magic)
