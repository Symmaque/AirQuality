//
// Created by Aurélien on 04/05/2021.
//

#include "Sensor.h"
#include <cmath>

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

const vector<Measure*> *Sensor::getMeasures() const {
    return measures;
}

void Sensor::setMeasures(vector<Measure*> *measures) {
    Sensor::measures = measures;
}

double Sensor::distance(const Sensor & to) const {
    return pow(to.latitude - this->latitude, 2) + pow(to.longitude - this->longitude, 2);
}

double Sensor::distance(double latitude, double longitude) {
    return pow(latitude - this->latitude, 2) + pow(longitude - this->longitude, 2);
}

Sensor::Sensor(int sensorId, double latitude, double longitude, vector<Measure*> *measures) {
    Sensor::latitude = latitude;
    Sensor::longitude = longitude;
    Sensor::sensorId = sensorId;
    Sensor::measures = measures;

}

Sensor::Sensor(int sensorId, double latitude, double longitude) {
    Sensor::latitude = latitude;
    Sensor::longitude = longitude;
    Sensor::sensorId = sensorId;
    Sensor::measures = new vector<Measure*>();
}


string Sensor::toString()
{
    return std::to_string(sensorId) + std::to_string(latitude) + std::to_string(longitude);
}

Sensor::Sensor() {
    Sensor::longitude = 0;
    Sensor::latitude = 0;
    Sensor::sensorId = 0;
}

ostream& operator<<(ostream& os, const Sensor & sensor)
{
    os << "Id : " << sensor.sensorId << endl;
    os << "Latitude : " << sensor.latitude << endl;
    os << "Longitude : " << sensor.longitude << endl;
    /*
    os << "Measures : " << endl;
    for (auto& measure : *sensor.measures){
        os << *measure << endl;
    }*/
    return os;
}
