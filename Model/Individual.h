//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_INDIVIDUAL_H
#define AIRQUALITY_INDIVIDUAL_H

#include <iostream>
#include "Sensor.h"
#include "User.h"

using namespace std;

class Individual : public User
{
protected:
    int id;
    bool malicious;
    int points;
    Sensor * sensor;

public:
    string toString();

    bool getMalicious() const;

    void setMalicious(bool malicious);

    int getPoints() const;

    int getId() const;
    void setId(const int id);

    void setPoints(int points);

    Sensor *getSensor() const;

    void setSensor(Sensor * sensor);

    Individual();

    friend ostream& operator<<(ostream& os, const Individual& individual);
};

#endif //AIRQUALITY_INDIVIDUAL_H
