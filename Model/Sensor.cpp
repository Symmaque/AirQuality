//
// Created by Aurélien on 04/05/2021.
//

#include "Sensor.h"

int Sensor::getSensorId() const {
    return sensorId;
}

void Sensor::setSensorId(int sensorId) {
    Sensor::sensorId = sensorId;
}

double Sensor::getLatitude() const {
    return latitude;
}

void Sensor::setLatitude(double latitude) {
    Sensor::latitude = latitude;
}

double Sensor::getLongitude() const {
    return longitude;
}

void Sensor::setLongitude(double longitude) {
    Sensor::longitude = longitude;
}

const vector<Measure> &Sensor::getMeasures() const {
    return measures;
}

void Sensor::setMeasures(const vector<Measure> &measures) {
    Sensor::measures = measures;
}
