//
// Created by Aurélien on 04/05/2021.
//

#include "Individual.h"

string Individual::toString() {
    return nullptr;
}

bool Individual::isMalicious() const {
    return malicious;
}

void Individual::setMalicious(bool malicious) {
    this->malicious = malicious;
}

int Individual::getPoints() const {
    return points;
}

void Individual::setPoints(int points) {
    this->points = points;
}

const Sensor &Individual::getSensor() const {
    return sensor;
}

void Individual::setSensor(const Sensor &sensor) {
    this->sensor = sensor;
}