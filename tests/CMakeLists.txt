cmake_minimum_required(VERSION 3.17)
project(AirQuality)
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "-DDEBUG -ansi -pedantic -Wall")


set(TEST_FILES
        IntegrityTest.cpp)
        #ClusteringTest.cpp)
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
        main.cpp
        ${INTERFACE_SRC}
        ${MODEL_SRC}
        ${SERVICES_SRC}
        ${DATA_SRC})

set(TEST_SRC
        main.cpp
        ${TEST_FILES}
        ${SRC})

set(EXE test_project)
add_executable(${EXE} ${TEST_SRC})
add_test(NAME test_project COMMAND ./test_project)


