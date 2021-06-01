//
// Created by Aurélien on 01/06/2021.
//

#include "DataTest.h"
#include "../src/services/Integrity.h"

bool DataTest::test() {
    //individual with invalid id should not be fetched
    auto * bad_individual = DataAccess::findIndividual(100);
    auto * valid_individual = DataAccess::findIndividual(0);
    bool test1 = bad_individual == nullptr && valid_individual != nullptr;

    //sensor with invalid id should not be fetched
    auto * bad_sensor = DataAccess::findSensor(200);
    auto * valid_sensor = DataAccess::findSensor(5);
    bool test2 = bad_sensor == nullptr && valid_sensor != nullptr;

    //test if data is well formed
    auto * individuals = DataAccess::getListIndividuals();
    bool test3 = individuals->size() == 4;

    //test if data is well formed
    auto * sensors = DataAccess::getListSensors();
    bool test4 = sensors->size() == 14;

    return test1 && test2 && test3 && test4;
}