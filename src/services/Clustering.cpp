//
// Created by Aurélien on 04/05/2021.
//

#include <algorithm>
#include <iostream>
#include "Clustering.h"
#include "../data/DataAccess.h"

using namespace std;

bool pairCompare(pair<Sensor *, double> p1, pair<Sensor *, double> p2) {
    return p1.second < p2.second;
}

Sensor *firstElement(const pair<Sensor *, double> &p) {
    return p.first;
}

/*
vector<Sensor *> *Clustering::findSimilarSensors(const Sensor &s, const time_t &startDate, const time_t &endDate) {
    if(startDate > endDate){
        cerr << "startDate is after the endDate" << endl;
        return nullptr;
    }
    auto * sensors = DataAccess::getListSensors();

    if (sensors->empty()) {
        cerr << "Warning in file " << __FILE__ << " at line " << __LINE__
             << " : vector sensors is empty thus the function " << __FUNCTION__ << " has returned nullptr" << endl;
        return nullptr;
    }
#ifdef DEBUG
    cout << "Begin sensors : " << endl;
    for(auto & sensor : sensors){
        cout << sensor << endl;
    }
    cout << "End sensors" << endl;
#endif
    double tempIndice;
    double tempDiff;
    vector<pair<Sensor *, double>> deltas;

    double indiceS = Stats::ATMOPeriodMean(s, startDate, endDate);
    for (auto &sensor : *sensors) {
        if (sensor.getSensorId() != s.getSensorId()) {

            tempIndice = Stats::ATMOPeriodMean(sensor, startDate, endDate);
            if(tempIndice == -1){
                cerr << "Invalid atmo period mean for the sensor : " << sensor << endl;
                continue;
            }
            tempDiff = abs(tempIndice - indiceS);
            auto tempPair = make_pair(&sensor, tempDiff);
            deltas.push_back(tempPair);
        }
    }
#ifdef DEBUG
    cout << "Begin deltas : " << endl;
    for(auto & delta : deltas){
        cout << "Delta.first :" << *delta.first << endl;
        cout << "Delta.second :" << delta.second << endl;
    }
    cout << "End deltas -------------------" << endl;
#endif

    sort(deltas.begin(), deltas.end(), pairCompare);

#ifdef DEBUG
    cout << "Begin deltas sorted : " << endl;
    for(auto & delta : deltas){
        cout << "Id :" << delta.first->getSensorId() << "   Delta : " << delta.second << endl;
    }
    cout << "End sorted deltas------------------" << endl;
#endif
    auto *results = new vector<Sensor *>();   //Do not forget to delete

    transform(deltas.begin(), deltas.end(), back_inserter(*results), firstElement);
#ifdef DEBUG
    cout << "Begin result : " << endl;
    for(auto & result : *results){
        cout << "result :" << *result << endl;
    }
    cout << "End result-----------------" << endl;
#endif
    return results;
}
*/

vector<Sensor *> *Clustering::findSimilarSensors(const Sensor &s, const time_t &startDate, const time_t &endDate) {
    if(startDate > endDate){
        cerr << "startDate is after the endDate" << endl;
        return nullptr;
    }
    auto * sensors = DataAccess::getListSensors();

    if (sensors->empty()) {
        cerr << "Warning in file " << __FILE__ << " at line " << __LINE__
             << " : vector sensors is empty thus the function " << __FUNCTION__ << " has returned nullptr" << endl;
        return nullptr;
    }
#ifdef DEBUG
    cout << "Begin sensors : " << endl;
    for(auto & sensor : sensors){
        cout << sensor << endl;
    }
    cout << "End sensors" << endl;
#endif
    double tempIndice;
    double tempDiff;
    vector<pair<Sensor *, double>> deltas;

    double indiceS = Stats::ATMOPeriodMean(s, startDate, endDate);
    for (auto &sensor : *sensors) {
        if (sensor.getSensorId() != s.getSensorId()) {

            tempIndice = Stats::ATMOPeriodMean(sensor, startDate, endDate);
            if(tempIndice == -1){
                //cerr << "Invalid atmo period mean for the sensor : " << sensor << endl;
                continue;
            }
            tempDiff = abs(tempIndice - indiceS);
            auto tempPair = make_pair(&sensor, tempDiff);
            deltas.push_back(tempPair);
        }
    }
#ifdef DEBUG
    cout << "Begin deltas : " << endl;
    for(auto & delta : deltas){
        cout << "Delta.first :" << *delta.first << endl;
        cout << "Delta.second :" << delta.second << endl;
    }
    cout << "End deltas -------------------" << endl;
#endif

    sort(deltas.begin(), deltas.end(), pairCompare);

#ifdef DEBUG
    cout << "Begin deltas sorted : " << endl;
    for(auto & delta : deltas){
        cout << "Id :" << delta.first->getSensorId() << "   Delta : " << delta.second << endl;
    }
    cout << "End sorted deltas------------------" << endl;
#endif
    auto *results = new vector<Sensor *>();   //Do not forget to delete

    transform(deltas.begin(), deltas.end(), back_inserter(*results), firstElement);
#ifdef DEBUG
    cout << "Begin result : " << endl;
    for(auto & result : *results){
        cout << "result :" << *result << endl;
    }
    cout << "End result-----------------" << endl;
#endif
    return results;
}
