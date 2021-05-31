//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_INTEGRITY_H
#define AIRQUALITY_INTEGRITY_H

#include "../model/Sensor.h"
#include "../model/Individual.h"
#include "../data/DataAccess.h"

class Integrity {
public:
    static vector<Sensor> sensorReliability();
    static vector<Individual> detectFraud();
    static bool detectUserFraud(Individual & value);
    static bool detectDefectiveSensor(const Sensor & value);
};

#endif //AIRQUALITY_INTEGRITY_H