//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_CLUSTERING_H
#define AIRQUALITY_CLUSTERING_H

using namespace std;
#include <ctime>
#include <vector>
#include <Sensor.h>
#include <DataAccesss.h>
#include <Stats.h>


class Clustering {

public:

    vector<Sensor> findSimilarSensors(Sensor s, time_t startDate, time_t endDate);


};


#endif //AIRQUALITY_CLUSTERING_H
