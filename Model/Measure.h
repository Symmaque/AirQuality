//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_MEASURE_H
#define AIRQUALITY_MEASURE_H


#include <ctime>
#include "Attribute.h"

class Measure {
protected:
    tm * date;
    int sensorId;
    Attribute attribute;
    double value;
    bool reliable;
public:
    tm *getDate() const;

    void setDate(tm *date);

    int getSensorId() const;

    void setSensorId(int sensorId);

    const Attribute &getAttribute() const;

    void setAttribute(const Attribute &attribute);

    double getValue() const;

    void setValue(double value);

    bool isReliable() const;

    void setReliable(bool reliable);
};


#endif //AIRQUALITY_MEASURE_H
