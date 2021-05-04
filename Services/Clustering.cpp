//
// Created by Aurélien on 04/05/2021.
//

#include <algorithm>
#include <iostream>
#include "Clustering.h"
#include "Stats.h"

using namespace std;

bool pairCompare(pair<Sensor*, double> p1, pair<Sensor*, double> p2){
    return p1.second < p2.second;
}

Sensor * firstElement( const pair<Sensor*, double> &p ) {
    return p.first;
}

vector<Sensor*> &Clustering::findSimilarSensors(const Sensor &s, const time_t & startDate, const time_t & endDate){

    //vector<Sensor> &sensors = DataAccess.getSensors();
    vector<Sensor> sensors = {*new Sensor(10,1,1), *new Sensor(11,13,10), *new Sensor(15,10,0)};
    //C'est un test
    cout << "Begin sensors : " << endl;
    for(auto & sensor : sensors){
        cout << sensor << endl;
    }
    cout << "End sensors" << endl;

    double tempIndice;
    double tempDiff;
    vector<pair<Sensor*, double>> deltas;

    double indiceS = Stats::ATMOPeriodMean(startDate, endDate, s.getLongitude(), s.getLatitude());
    for(auto & sensor : sensors){
        if (sensor.getSensorId()!=s.getSensorId()){
            tempIndice = Stats::ATMOPeriodMean(startDate, endDate, sensor.getLongitude(), sensor.getLatitude());
            //tempDiff = abs(tempIndice - indiceS);
            tempDiff = tempIndice;
            auto tempPair = make_pair(&sensor,tempDiff);
            deltas.push_back(tempPair);
        }
    }

    cout << "Begin deltas : " << endl;
    for(auto & delta : deltas){
        cout << "Delta.first :" << *delta.first << endl;
        cout << "Delta.second :" << delta.second << endl;
    }
    cout << "End deltas -------------------" << endl;


    sort(deltas.begin(), deltas.end(), pairCompare);

    cout << "Begin deltas sorted : " << endl;
    for(auto & delta : deltas){
        //cout << "Delta.first :" << *delta.first << endl;
        cout << "Delta.second :" << delta.second << endl;
    }
    cout << "End sorted deltas------------------" << endl;

    auto * results = new vector<Sensor*>();   //Do not forget to delete

    transform( deltas.begin(), deltas.end(), back_inserter(*results), firstElement);

    cout << "Begin result : " << endl;
    for(auto & result : *results){
        cout << "result :" << *result << endl;
    }
    cout << "End result-----------------" << endl;

    return *results;
}


