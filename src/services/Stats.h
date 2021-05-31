//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_STATS_H
#define AIRQUALITY_STATS_H


#include <ctime>
#include "../model/Sensor.h"

class Stats {
public:
    static double ATMOPeriodMean(const Sensor & sensor, const time_t & startDate, const time_t &endDate);
    static double ATMOSensorLifespanMean(const Sensor &sensor);
    static int ATMOGaz(const string& unit, double value);
};


#endif //AIRQUALITY_STATS_H
