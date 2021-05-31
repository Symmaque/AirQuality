//
// Created by Aurélien on 04/05/2021.
//

#include "Integrity.h"
#include "Stats.h"

#include <cmath>
#include <algorithm>

using namespace std;

vector<Sensor> Integrity::sensorReliability() {
    return *new vector<Sensor>;
}

vector<Individual> Integrity::detectFraud() {
    vector<Individual> allIndividuals = *DataAccess::getListIndividuals();
    vector<Individual> maliciousIndividuals;
    for (const Individual& individual : allIndividuals) {
        bool malicious = detectUserFraud(individual);
        if (malicious) {
            maliciousIndividuals.push_back(individual);
        }
    }

    return maliciousIndividuals;
}

bool Integrity::detectUserFraud(const Individual &value) {
    return detectDefectiveSensor(*value.getSensor());
}

bool Integrity::detectDefectiveSensor(const Sensor &value) {

    double valueATMO = Stats::ATMOSensorLifespanMean(value);

    //cout << "Value ATMO " << valueATMO << endl;

    vector<Sensor> allSensors = *DataAccess::getListSensors();
    vector<Sensor> closeSensors; //TODO Maybe use a map sensor-distance to avoid recomputing

    sort(allSensors.begin(), allSensors.end(), [&value](Sensor &a, Sensor &b) {
        return a.distance(value) < b.distance(value);
    });

    for (auto it = allSensors.begin(); it != allSensors.end(); ++it) {
        if (it->getSensorId() == value.getSensorId()) {
            allSensors.erase(it);
        }
    }

    int i = 0;
    //We loop through the 10 closest sensors without going out of the index bound
    for (auto it = allSensors.begin(); it != allSensors.end() && i < 10; ++it, i++) {
        if (it->distance(value) ==
            0) { //It means it is the current sensor (value) and we have to exclude it from the comparison
            allSensors.erase(it);
        }
        if (it->distance(value) < 1.0) { //Only include close sensors
            //cout << " Distance " << it->distance(value) << endl;
            closeSensors.push_back(*it);
        }
    }


    //Compute average
    unsigned long n = closeSensors.size();
    double sumTotal = 0.0;
    for (const auto &sensor : closeSensors) {
        sumTotal += Stats::ATMOSensorLifespanMean(sensor); //TODO Add valid parameters
    }
    double average = sumTotal / (double) n;


    //Compute standard deviation
    double sumDiffs = 0.0;
    for (const auto &sensor : closeSensors) {
        sumDiffs += pow(average - Stats::ATMOSensorLifespanMean(sensor), 2);
    }

    double variance = sumDiffs / (double) n;
    double standardDeviation = sqrt(variance);
    //Confidence interval inclusion check
    double confidence = standardDeviation / sqrt(n);

#ifdef DEBUG
    cout << " Target = " << valueATMO << endl;
    cout << " average " << average << endl;
    cout << " SD = " << standardDeviation << endl;
    cout << " confidence = " << confidence << endl;
    cout << " lower bound " << average - confidence;
    cout << " upper bound " << average + confidence;
#endif

    return valueATMO < (average - confidence) || valueATMO > (average + confidence);
}