//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_STATS_H
#define AIRQUALITY_STATS_H


#include "../Model/Sensor.h"

class Stats {
    public:
    static double ATMOInstantMean(const Sensor & sensor);
};


#endif //AIRQUALITY_STATS_H
