//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_INDIVIDUAL_H
#define AIRQUALITY_INDIVIDUAL_H

#include <iostream>
#include "Sensor.h"
#include "User.h"

using namespace std;

class Individual : public User {
protected:
    bool malicious;
    int points;
    Sensor sensor;

public:
    string toString();

    bool getMalicious() const;

    void setMalicious(bool malicious);

    int getPoints() const;

    void setPoints(int points);

    const Sensor & getSensor() const;

    void setSensor(const Sensor &sensor);
};


#endif //AIRQUALITY_INDIVIDUAL_H
