//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_SENSOR_H
#define AIRQUALITY_SENSOR_H

#include <vector>
#include "Measure.h"

using namespace std;

class Sensor {

protected:
    int sensorId;
    double latitude;
    double longitude;
    vector<Measure> measures;
public:
    int getSensorId() const;

    void setSensorId(int sensorId);

    double getLatitude() const;

    void setLatitude(double latitude);

    double getLongitude() const;

    void setLongitude(double longitude);

    const vector<Measure> &getMeasures() const;

    void setMeasures(const vector<Measure> &measures);

    double distance(const Sensor & to) const;
    double distance(double latitude, double longitude);

};


#endif //AIRQUALITY_SENSOR_H
