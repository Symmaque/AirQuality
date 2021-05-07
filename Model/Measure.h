//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_MEASURE_H
#define AIRQUALITY_MEASURE_H

#include <ctime>
#include "Attribute.h"
#include <iostream>
typedef struct Date{
    string year;
    string month;
    string day;
    Date(const string& date);
    Date(string year, string month, string day);
    Date();
    friend ostream& operator<<(ostream& os, const Date& date);
}Date;
class Measure
{
protected:
    Date * date;
    int sensorId;
    Attribute attribute;
    double value;
    bool reliable;

public:
    Measure();

    Date *getDate() const;

    void setDate(const Date *date);

    int getSensorId() const;

    void setSensorId(int sensorId);

    const Attribute &getAttribute() const;

    void setAttribute(const Attribute &attribute);

    double getValue() const;

    void setValue(double value);

    bool isReliable() const;

    void setReliable(bool reliable);

    friend ostream & operator<<(ostream&, const Measure & measure);

    string toString();
};

#endif //AIRQUALITY_MEASURE_H
