//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_INTEGRITY_H
#define AIRQUALITY_INTEGRITY_H

#include "../Model/Sensor.h"
#include "../Model/Individual.h"
#include "../Data/DataAccess.h"

class Integrity {
public:
    vector<Sensor> sensorReliability();
    vector<Individual> detectFraud();
    bool detectUserFraud(Individual value);
    bool detectDefectiveSensor(Sensor value);


};


#endif //AIRQUALITY_INTEGRITY_H
