//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_CLUSTERING_H
#define AIRQUALITY_CLUSTERING_H

using namespace std;
#include <ctime>
#include <vector>
#include "../Model/Sensor.h"

#include "Stats.h"

class Clustering {

public:

    static vector<Sensor*> &findSimilarSensors(const Sensor &s, const tm & startDate, const tm & endDate);


};


#endif //AIRQUALITY_CLUSTERING_H
