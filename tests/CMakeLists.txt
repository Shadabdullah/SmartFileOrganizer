cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER "/usr/local/bin/clang++")

project(tests)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

find_package(SndFile)
find_package(LibArchive REQUIRED)

#Functions to be tested

file(GLOB_RECURSE SOURCE_DIRS LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/../src/*")

set(SOURCES "")

foreach(ITEM ${SOURCE_DIRS})
    if(NOT IS_DIRECTORY ${ITEM})
	    if(${ITEM} STREQUAL "${CMAKE_SOURCE_DIR}/../src/main.c")
	    
	    else()	
		list(APPEND SOURCES ${ITEM})
	    endif()
	
    endif()
endforeach()



message(STATUS "Sources found: ${SOURCES}")

include_directories(./../include ./include)
add_executable(${PROJECT_NAME} ${SOURCES} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main magic archive sndfile ogg vorbis vorbisenc FLAC opus mp3lame mpg123)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

