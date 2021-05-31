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
    auto * time = localtime(&cleaner.startDate);
    os << "Cleaner : " << cleaner.id << endl << "Lat :  " << cleaner.latitude << ", Long : " << cleaner.longitude << endl;
    os << "Start Date : " << time->tm_year + 1900 << "-" << time->tm_mon + 1 << "-" << time->tm_mday << endl;
    time = localtime(&cleaner.endDate);
    os << "End Date : " << time->tm_year + 1900 << "-" << time->tm_mon + 1 << "-" << time->tm_mday << endl;

    return os;
}

Cleaner::Cleaner(int id, double latitude, double longitude, time_t startDate, time_t endDate){
    Cleaner::id = id;
    Cleaner::latitude = latitude;
    Cleaner::longitude = longitude;
    Cleaner::startDate = startDate;
    Cleaner::endDate = endDate;
}

