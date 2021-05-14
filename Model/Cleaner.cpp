//
// Created by Aurélien on 04/05/2021.
//

#include "Cleaner.h"


int Cleaner::getId() const {
    return id;
}

void Cleaner::setId(int id) {
    Cleaner::id = id;
}

double Cleaner::getLatitude() const {
    return latitude;
}

void Cleaner::setLatitude(double latitude) {
    Cleaner::latitude = latitude;
}

double Cleaner::getLongitude() const {
    return longitude;
}

void Cleaner::setLongitude(double longitude) {
    Cleaner::longitude = longitude;
}

time_t Cleaner::getStartDate() const {
    return startDate;
}

void Cleaner::setStartDate(time_t startDate) {
    Cleaner::startDate = startDate;
}

time_t Cleaner::getEndDate() const {
    return endDate;
}

void Cleaner::setEndDate(time_t endDate) {
    Cleaner::endDate = endDate;
}

ostream &operator<<(ostream &os, const Cleaner &cleaner) {
    os << "il faut implementer cette fonction pour les cleaners " << endl;
    return os;
}

