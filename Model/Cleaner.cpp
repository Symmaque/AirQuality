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

tm *Cleaner::getStartDate() const {
    return startDate;
}

void Cleaner::setStartDate(tm *startDate) {
    Cleaner::startDate = startDate;
}

tm *Cleaner::getEndDate() const {
    return endDate;
}

void Cleaner::setEndDate(tm *endDate) {
    Cleaner::endDate = endDate;
}

const Provider &Cleaner::getProvider() const {
    return provider;
}

void Cleaner::setProvider(const Provider &provider) {
    Cleaner::provider = provider;
}