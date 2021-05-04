//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_STATS_H
#define AIRQUALITY_STATS_H


#include <ctime>
#include "../Model/Sensor.h"

class Stats {
public:
    static double ATMOPeriodMean(const tm & startDate, const tm &endDate, double longitude, double latitude);
    static double ATMOInstantMean(const tm &date, double longitude, double latitude);
    static double ATMOInstantMean(const Sensor & sensor);
};


#endif //AIRQUALITY_STATS_H
