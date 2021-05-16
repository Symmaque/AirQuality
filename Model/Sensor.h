//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_SENSOR_H
#define AIRQUALITY_SENSOR_H

#include <vector>
#include <iostream>
#include "Measure.h"

using namespace std;

class Sensor
{

protected:
    int sensorId;
    double latitude;
    double longitude;
    vector<Measure*> * measures;

public:
    Sensor(int sensorId, double latitude, double longitude, vector<Measure*> *measures);
    Sensor(int sensorId, double latitude, double longitude);
    Sensor();

    int getSensorId() const;

    void setSensorId(int sensorId);

    double getLatitude() const;

    void setLatitude(double latitude);

    double getLongitude() const;

    void setLongitude(double longitude);

    const vector<Measure*> *getMeasures() const;

    void setMeasures(vector<Measure*> *measures);

    double distance(const Sensor &to) const;
    double distance(double latitude, double longitude);

    string toString();
    friend ostream& operator<<(ostream& os, const Sensor & sensor);


};

#endif //AIRQUALITY_SENSOR_H
