//
// Created by Aurélien on 01/06/2021.
//

#include "StatsTest.h"
#include "../src/services/Stats.h"
#include "../src/data/DataAccess.h"

bool StatsTest::test() {

    //test the values of the Atmo indexes sensors 12 et 13
    auto * sensor12 = DataAccess::findSensor(12);
    auto * sensor13 = DataAccess::findSensor(13);
    double atmo12 = Stats::ATMOSensorLifespanMean(*sensor12);
    double atmo13 = Stats::ATMOSensorLifespanMean(*sensor13);

    return atmo12 == 1 && atmo13 == 10;
}