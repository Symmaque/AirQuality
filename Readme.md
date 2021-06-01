#Bienvenue sur l'application AirQuality

##Structure : 

    AirQuality
    |--CMakeList.txt
    |--cmake-build-debug
    |--resources
        |--release
            |--accounts.csv
            |--attributes.csv
            |--cleaners.csv
            |--measurements.csv
            |--providers.csv
            |--sensors.csv
            |--users.csv
        |--tests
            |--*
    |--src
        |--CMakeList.txt
        |--main.cpp
        |--data
            |--DataAccess.cpp/.h
            |--Reader.cpp/.h
        |--interface
            |--GovernmentInterface.cpp/.h
            |--IndividualInterface.cpp/.h
            |--InterfaceUtils.cpp/.h
            |--ProviderInterface.cpp/.h
        |--model
            |--Attribute.cpp/.h
            |--Cleaner.cpp/.h
            |--Government.cpp/.h
            |--Individual.cpp/.h
            |--Measure.cpp/.h
            |--Provider.cpp/.h
            |--Sensor.cpp/.h
            |--User.cpp/.h
        |--services
            |--ClearAnalysis.cpp/.h
            |--Clustering.cpp/.h
            |--Integrity.cpp/.h
            |--Stats.cpp/.h
    |--tests
        |--CMakeList.txt
        |--clusteringTests
            |--ClusteringTest.cpp/.h
            |--clusteringMain.cpp
        |--dataTests
            |--DataTest.cpp/.h
            |--dataMain.cpp
        |--integrityTests
            |--IntegrityTest.cpp/.h
            |--integrityMain.cpp
        |--statsTests
            |--StatsTest.cpp/.h
            |--statsMain.cpp
##Build, run and test
####Ce projet utilise CMake pour build and run ainsi que CTest pour lancer les tests

    --> executer cd cmake-build-debug
    --> executer cmake ..
    --> executer make

        Scanning dependencies of target AirQuality_lib
        [  2%] Building CXX object src/CMakeFiles/AirQuality_lib.dir/main.cpp.o
        ...
        [ 58%] Linking CXX static library libAirQuality_lib.a
        [ 58%] Built target AirQuality_lib
        Scanning dependencies of target AirQuality
        [ 61%] Building CXX object src/CMakeFiles/AirQuality.dir/main.cpp.o
        [ 64%] Linking CXX executable AirQuality
        [ 64%] Built target AirQuality
        Scanning dependencies of target stats_test
        [ 67%] Building CXX object tests/CMakeFiles/stats_test.dir/statsTests/statsMain.cpp.o
        ...
        [ 73%] Built target stats_test
        Scanning dependencies of target data_test
        [ 76%] Building CXX object tests/CMakeFiles/data_test.dir/dataTests/dataMain.cpp.o
        ...
        [ 82%] Built target data_test
        Scanning dependencies of target clustering_test
        [ 85%] Building CXX object tests/CMakeFiles/clustering_test.dir/clusteringTests/clusteringMain.cpp.o
        ...
        [ 91%] Built target clustering_test
        Scanning dependencies of target integrity_test
        [ 94%] Building CXX object tests/CMakeFiles/integrity_test.dir/integrityTests/integrityMain.cpp.o
        ...
        [100%] Built target integrity_test

    --> executer make run pour lancer l'application AirQuality
    --> executer make test pour lancer les tests