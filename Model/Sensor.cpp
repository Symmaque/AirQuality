//
// Created by Aurélien on 04/05/2021.
//

#include "Sensor.h"
#include "math.h"

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

double Sensor::distance(Sensor & to) {
    return pow(to.latitude - this->latitude, 2) + pow(to.longitude - this->longitude, 2);
}

double Sensor::distance(double latitude, double longitude) {
    return pow(latitude - this->latitude, 2) + pow(longitude - this->longitude, 2);
}