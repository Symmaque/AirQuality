cmake_minimum_required(VERSION 3.17)
project(AirQuality)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "-DDEBUG -ansi -pedantic -Wall")
set(EXE AirQuality)

set(SRC ${CMAKE_SOURCE_DIR}/src)
set(TESTS ${CMAKE_SOURCE_DIR}/tests)

add_subdirectory(${SRC})
add_subdirectory(${TESTS})