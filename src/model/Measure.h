//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_MEASURE_H
#define AIRQUALITY_MEASURE_H

#include <ctime>
#include "Attribute.h"
#include <iostream>

class Measure
{
protected:
    time_t * date;
    int sensorId;
    Attribute * attribute;
    double value;
    bool reliable;

public:
    Measure();

    time_t *getDate() const;

    void setDate(time_t date);

    int getSensorId() const;

    void setSensorId(int sensorId);

    const Attribute &getAttribute() const;

    void setAttribute(Attribute *attribute);

    double getValue() const;

    void setValue(double value);

    bool isReliable() const;

    void setReliable(bool reliable);

    friend ostream &operator<<(ostream &, const Measure &measure);

    ~Measure();

    string toString();
};

#endif //AIRQUALITY_MEASURE_H
