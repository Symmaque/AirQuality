cmake_minimum_required(VERSION 3.17)
project(AirQuality)
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "-DDEBUG -ansi -pedantic -Wall")




set(INTERFACE_SRC
        ../src/interface/GovernmentInterface.cpp
        ../src/interface/IndividualInterface.cpp
        ../src/interface/InterfaceUtils.cpp
        ../src/interface/ProviderInterface.cpp)

set(MODEL_SRC
        ../src/model/Attribute.cpp
        ../src/model/Cleaner.cpp
        ../src/model/Government.cpp
        ../src/model/Individual.cpp
        ../src/model/Measure.cpp
        ../src/model/Provider.cpp
        ../src/model/Sensor.cpp
        ../src/model/User.cpp)

set(SERVICES_SRC
        ../src/services/ClearAnalysis.cpp
        ../src/services/Clustering.cpp
        ../src/services/Integrity.cpp
        ../src/services/Stats.cpp)

set(DATA_SRC
        ../src/data/DataAccess.cpp
        ../src/data/Reader.cpp)


set(SRC
        ${INTERFACE_SRC}
        ${MODEL_SRC}
        ${SERVICES_SRC}
        ${DATA_SRC})

set(INTEGRITY_SRC
        integrityMain.cpp
        IntegrityTest.cpp
        ${SRC})

set(CLUSTERING_SRC
        clusteringMain.cpp
        ClusteringTest.cpp
        ${SRC})

set(INTEGRITY integrity_test)
set(CLUSTERING clustering_test)
add_executable(${INTEGRITY} ${INTEGRITY_SRC})
add_executable(${CLUSTERING} ${CLUSTERING_SRC})
add_test(NAME integrity_test COMMAND ./integrity_test)
add_test(NAME clustering_test COMMAND ./clustering_test)


