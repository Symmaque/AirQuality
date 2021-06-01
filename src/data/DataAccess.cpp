//
// Created by Aurélien on 04/05/2021.
//
#include "DataAccess.h"

#include <iostream>
#include "Reader.h"

using namespace std;

vector<User> DataAccess::listUsers = {};
vector<Sensor> DataAccess::listSensors = {};
vector<Attribute> DataAccess::listAttributes = {};
vector<Measure> DataAccess::listMeasures = {};
vector<Provider> DataAccess::listProviders = {};
vector<Individual> DataAccess::listIndividuals = {};
vector<Cleaner> DataAccess::listCleaners = {};

vector<User> *DataAccess::getListUsers(){
    return &listUsers;
}

vector<Sensor> *DataAccess::getListSensors()
{
    return &listSensors;
}

vector<Provider> *DataAccess::getListProviders()
{
    return &listProviders;
}

vector<Measure> *DataAccess::getListMeasures()
{
    return &listMeasures;
}

vector<Attribute> *DataAccess::getListAttribute()
{
    return &listAttributes;
}

void DataAccess::init(const string& folder){
    Reader::readAttributes(folder + "attributes.csv");
    Reader::readMeasures(folder + "measurements.csv");
    Reader::readSensor(folder + "sensors.csv");
    Reader::readCleaners(folder + "cleaners.csv");
    Reader::readIndividuals(folder + "users.csv");
    Reader::readProviders(folder + "providers.csv");
    Reader::readAccounts(folder + "accounts.csv");
}

vector<Individual> *DataAccess::getListIndividuals() {
    return &listIndividuals;
}

vector<Cleaner> *DataAccess::getListCleaners() {
    return &listCleaners;
}

Individual * DataAccess::findIndividual(int id) {
    for(auto & it : listIndividuals) {
        if(it.getId() == id) return &it;
    }
    return nullptr;
}

Sensor * DataAccess::findSensor(int id) {
    for(auto & it : listSensors) {
        if(it.getSensorId() == id) {
            return &it;
        }
    }
    return nullptr;
}

void DataAccess::removeSensor(Sensor * sensor) {
    removeSensor(sensor->getSensorId());
    removeMeasures(sensor->getSensorId());
}

void DataAccess::removeMeasures(int sensorId){
    for (auto it = listMeasures.begin(); it != listMeasures.end(); ++it) {
        if (it->getSensorId() == sensorId) {
            listMeasures.erase(it);
        }
    }
}

void DataAccess::removeSensor(int id) {
    for (auto it = listSensors.begin(); it != listSensors.end(); ++it) {
        if (it->getSensorId() == id) {
            listSensors.erase(it);
        }
    }
}