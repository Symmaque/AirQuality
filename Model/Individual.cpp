//
// Created by Aurélien on 04/05/2021.
//

#include "Individual.h"

bool Individual::getMalicious() const {
    return malicious;
}

void Individual::setMalicious(bool malicious) {
    Individual::malicious = malicious;
}

int Individual::getPoints() const {
    return points;
}

void Individual::setPoints(int points) {
    Individual::points = points;
}

const Sensor & Individual::getSensor() const {
    return sensor;
}

void Individual::setSensor(const Sensor &sensor) {
    Individual::sensor = sensor;
}

string Individual::toString() {
    return "individual toString";
}
