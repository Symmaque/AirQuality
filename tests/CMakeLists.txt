cmake_minimum_required(VERSION 3.17)
project(AirQuality)
set(CMAKE_CXX_STANDARD 11)


set(INTEGRITY_SRC
        integrityTests/integrityMain.cpp
        integrityTests/IntegrityTest.cpp)

set(CLUSTERING_SRC
        clusteringTests/clusteringMain.cpp
        clusteringTests/ClusteringTest.cpp)

set(DATA_SRC
        dataTests/dataMain.cpp
        dataTests/DataTest.cpp)

set(STATS_SRC
        statsTests/statsMain.cpp
        statsTests/StatsTest.cpp)

set(INTEGRITY integrity_test)
set(CLUSTERING clustering_test)
set(DATA data_test)
set(STATS stats_test)

add_executable(${INTEGRITY} ${INTEGRITY_SRC})
add_executable(${CLUSTERING} ${CLUSTERING_SRC})
add_executable(${DATA} ${DATA_SRC})
add_executable(${STATS} ${STATS_SRC})

add_test(NAME integrity_test COMMAND ./integrity_test)
add_test(NAME clustering_test COMMAND ./clustering_test)
add_test(NAME data_test COMMAND ./data_test)
add_test(NAME stats_test COMMAND ./stats_test)

target_link_libraries(${INTEGRITY} PUBLIC ${CMAKE_PROJECT_NAME}_lib)
target_link_libraries(${CLUSTERING} PUBLIC ${CMAKE_PROJECT_NAME}_lib)
target_link_libraries(${DATA} PUBLIC ${CMAKE_PROJECT_NAME}_lib)
target_link_libraries(${STATS} PUBLIC ${CMAKE_PROJECT_NAME}_lib)


