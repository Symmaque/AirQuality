//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_INDIVIDUAL_H
#define AIRQUALITY_INDIVIDUAL_H

#include <ctime>
#include <string>
#include "Sensor.h"

using namespace std;

class Individual {

    private:
    bool malicious;
    int points;
    Sensor sensor;
public:

    bool isMalicious() const;
    void setMalicious(bool value);
    int getPoints() const;
    void setPoints(int points);
    const Sensor & getSensor() const;
    void setSensor(const Sensor &sensor);
    string toString();

};


#endif //AIRQUALITY_INDIVIDUAL_H
