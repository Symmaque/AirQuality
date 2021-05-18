cmake_minimum_required(VERSION 3.17)
project(AirQuality)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "-DDEBUG -ansi -pedantic -Wall")
add_executable(AirQuality main.cpp Model/User.cpp Model/User.h Model/Individual.cpp Model/Individual.h Model/Cleaner.cpp Model/Cleaner.h Model/Provider.cpp Model/Provider.h Model/Government.cpp Model/Government.h Model/Sensor.cpp Model/Sensor.h Model/Measure.cpp Model/Measure.h Model/Attribute.cpp Model/Attribute.h Interface/IndividualInterface.cpp Interface/IndividualInterface.h Interface/GovernmentInterface.cpp Interface/GovernmentInterface.h Interface/ProviderInterface.cpp Interface/ProviderInterface.h Services/Stats.cpp Services/Stats.h Services/Clustering.cpp Services/Clustering.h Services/ClearAnalysis.cpp Services/ClearAnalysis.h Services/Integrity.cpp Services/Integrity.h Data/Reader.cpp Data/Reader.h Data/DataAccess.cpp Data/DataAccess.h Interface/InterfaceUtils.cpp Interface/InterfaceUtils.h)