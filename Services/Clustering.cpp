//
// Created by Aurélien on 04/05/2021.
//

#include "Clustering.h"

bool pairCompare(pair<Sensor&, double> p1, pair<Sensor&, double> p2){
    return p1.second < p2.second;
}

int firstElement( const pair<Sensor&, double> &p ) {
    return p.first;
}

vector<Sensor> &findSimilarSensors(const Sensor &s, time_t startDate, time_t endDate){

    vector<Sensor> &sensors = DataAccess.getSensors();
    //C'est un test

    double tempIndice;
    double tempDiff;
    vector<pair<Sensor&, double>> deltas;

    double indiceS = ATMOPeriodMean(startDate, endDate, s.getLongitude(), s.getLatitude());
    for(auto it = sensors.begin(); it!= sensors.end(); ++it ){
        if (it->getSensorId()!=s.getSensorId()){
            tempIndice = ATMOPeriodMean(startDate, endDate, it->getLongitude(), it->getLatitude());
            tempDiff = abs(tempIndice - indiceS);
            deltas.push(make_pair(*it,tempDiff));
        }
    }

    sort(deltas.begin(), deltas.end(), pairCompare);
    transform( deltas.begin(), deltas.end(), back_inserter(deltas), firstElement);

    return deltas;
}