//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_STATS_H
#define AIRQUALITY_STATS_H


#include <ctime>
#include "../Model/Sensor.h"

class Stats {
public:
    static double ATMOPeriodMean(const time_t & startDate, const time_t &endDate, double longitude, double latitude);
    static double ATMOInstantMean(const Sensor & sensor);
    static double ATMOInstantMean(const time_t &date, double longitude, double latitude);

    double ATMOInstantMean(time_t date, const Sensor &sensor);

    static double ATMOSensorLifespanMean(const Sensor &sensor);

    static int ATMOGaz(const string& unit, double value);
};


#endif //AIRQUALITY_STATS_H
