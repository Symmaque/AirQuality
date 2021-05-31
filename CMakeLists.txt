cmake_minimum_required(VERSION 3.17)
project(AirQuality)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)

set(EXE AirQuality)

set(SRC ${CMAKE_SOURCE_DIR}/src)
set(TESTS ${CMAKE_SOURCE_DIR}/tests)



add_subdirectory(${SRC})
add_subdirectory(${TESTS})


include_directories(${SRC})
add_custom_target(run COMMAND ./AirQuality WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/cmake-build-debug/src)

