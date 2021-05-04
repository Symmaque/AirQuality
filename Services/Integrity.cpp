//
// Created by Aurélien on 04/05/2021.
//

#include "Integrity.h"
#include "Stats.h"

//#include <algorithm>
#include <cmath>
#include <algorithm>

using namespace std;
vector<Sensor> Integrity::sensorReliability() {
    return *new vector<Sensor>;
}

vector<Individual> Integrity::detectFraud() {
    vector<User> users = *DataAccess::getListUsers();
    vector<Individual> individuals;
    for(User user : users) {
        if(typeid(user) == typeid(Individual)) {
            User * ptrUser = &user;
            auto * individual = reinterpret_cast<Individual*>(ptrUser);
            bool malicious = detectUserFraud(*individual);
            if(malicious) {
                individuals.push_back(*individual);
            }
        }
    }

    return individuals;
}

bool Integrity::detectUserFraud(Individual & value) {
    return detectDefectiveSensor(value.getSensor());
}

bool Integrity::detectDefectiveSensor(const Sensor & value) {

    double valueATMO = Stats::ATMOInstantMean(value);
    vector<Sensor> & allSensors = *DataAccess::getListSensors();
    vector<Sensor> closeSensors; //TODO Maybe use a map sensor-distance to avoid recomputing



    sort (allSensors.begin(), allSensors.end(), [&value](Sensor& a,Sensor& b) {
        return a.distance(value) < b.distance(value);
    });

    int i = 0;
    //We loop through the 10 closest sensors without going out of the index bound
    for(auto it = allSensors.begin(); it != allSensors.end() && i < 10; ++it, i++) {
        if(it->distance(value) < 100.0) { //Only include close sensors
            closeSensors.push_back(*it);
        }
    }

    unsigned long n = closeSensors.size();
    double sumTotal = 0.0;
    //Compute average
    for(auto sensor : closeSensors) {
        sumTotal += Stats::ATMOInstantMean(sensor); //TODO Add valid parameters
    }
    double average = sumTotal / n;

    double sumDiffs = 0.0;
    //Compute standard deviation
    for(auto sensor : closeSensors) {
        sumDiffs = pow(average - Stats::ATMOInstantMean(sensor), 2);
    }
    double variance = sumDiffs / n;
    double standardDeviation = sqrt(variance);
    //Confidence interval inclusion check
    double confidence = 2 * standardDeviation / sqrt(n);

    return (average - confidence) < valueATMO || average + confidence > valueATMO;
}