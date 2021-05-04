//
// Created by Aurélien on 04/05/2021.
//

#include "Measure.h"

tm *Measure::getDate() const {
    return date;
}

void Measure::setDate(tm *date) {
    Measure::date = date;
}

int Measure::getSensorId() const {
    return sensorId;
}

void Measure::setSensorId(int sensorId) {
    Measure::sensorId = sensorId;
}

const Attribute &Measure::getAttribute() const {
    return attribute;
}

void Measure::setAttribute(const Attribute &attribute) {
    Measure::attribute = attribute;
}

double Measure::getValue() const {
    return value;
}

void Measure::setValue(double value) {
    Measure::value = value;
}

bool Measure::isReliable() const {
    return reliable;
}

void Measure::setReliable(bool reliable) {
    Measure::reliable = reliable;
}
