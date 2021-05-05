#include <iostream>
#include <ctime>
#include "Services/Clustering.h"

using namespace std;


void testfindSimilarSensors(){
    auto sensor1 = Sensor(1,2.0,2.0);
    time_t start = time(nullptr);
    time_t end = time(nullptr);
    cout << "Start : " << start << endl;
    cout << "End : " << end<< endl;
    auto * similarSensors = Clustering::findSimilarSensors(sensor1,start,end);
    if(similarSensors == nullptr){
        cerr << "similarSensor is nullptr " << endl;
        return;
    }

    for(auto & sensor : *similarSensors){
        cout << *sensor << endl;
    }

    delete similarSensors;
}

int main() {

    testfindSimilarSensors();

    return 0;
}
