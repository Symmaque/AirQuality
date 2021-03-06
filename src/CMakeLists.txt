cmake_minimum_required(VERSION 3.17)
project(AirQuality)
set(CMAKE_CXX_STANDARD 11)

set(EXE AirQuality)
set(LIB ${EXE}_lib)

set(INTERFACE_SRC
        ./interface/GovernmentInterface.cpp
        ./interface/IndividualInterface.cpp
        ./interface/InterfaceUtils.cpp
        ./interface/ProviderInterface.cpp)

set(MODEL_SRC
        ./model/Attribute.cpp
        ./model/Cleaner.cpp
        ./model/Government.cpp
        ./model/Individual.cpp
        ./model/Measure.cpp
        ./model/Provider.cpp
        ./model/Sensor.cpp
        ./model/User.cpp)

set(SERVICES_SRC
        ./services/ClearAnalysis.cpp
        ./services/Clustering.cpp
        ./services/Integrity.cpp
        ./services/Stats.cpp)

set(DATA_SRC
        ./data/DataAccess.cpp
        ./data/Reader.cpp)

set(SRC
        main.cpp
        ${INTERFACE_SRC}
        ${MODEL_SRC}
        ${SERVICES_SRC}
        ${DATA_SRC})

add_library(${LIB} STATIC ${SRC})
add_executable(${EXE} main.cpp)
target_link_libraries(${EXE} PUBLIC ${LIB})
