//
// Created by Aurélien on 04/05/2021.
//

#include <algorithm>
#include "Clustering.h"
#include "Stats.h"

using namespace std;

bool pairCompare(pair<Sensor*, double> p1, pair<Sensor*, double> p2){
    return p1.second < p2.second;
}

Sensor * firstElement( const pair<Sensor*, double> &p ) {
    return p.first;
}

vector<Sensor*> &Clustering::findSimilarSensors(const Sensor &s, const tm & startDate, const tm & endDate){

    //vector<Sensor> &sensors = DataAccess.getSensors();
    vector<Sensor> sensors = {*new Sensor(10,0,0), *new Sensor(10,0,0), *new Sensor(10,0,0)};
    //C'est un test

    double tempIndice;
    double tempDiff;
    vector<pair<Sensor*, double>> deltas;

    double indiceS = Stats::ATMOPeriodMean(startDate, endDate, s.getLongitude(), s.getLatitude());
    for(auto & sensor : sensors){
        if (sensor.getSensorId()!=s.getSensorId()){
            tempIndice = Stats::ATMOPeriodMean(startDate, endDate, sensor.getLongitude(), sensor.getLatitude());
            tempDiff = abs(tempIndice - indiceS);
            auto tempPair = make_pair(&sensor,tempDiff);
            deltas.push_back(tempPair);
        }
    }

    sort(deltas.begin(), deltas.end(), pairCompare);
    auto * result = new vector<Sensor*>();   //Do not forget to delete
    transform( deltas.begin(), deltas.end(), back_inserter(*result), firstElement);

    return *result;
}


