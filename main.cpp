#include <iostream>
#include <ctime>
#include "Services/Clustering.h"
#include "Model/Sensor.h"
using namespace std;
int foo(int & n){
    return 2*n;
}


void testfindSimilarSensors(){
    auto * sensor = new Sensor(1,2.0,2.0);
    time_t start = time(nullptr);
    time_t end = time(nullptr);
    cout << "Start : " << start << endl;
    cout << "End : " << end<< endl;
    Clustering::findSimilarSensors(*sensor,start,end);
}

int main() {

    //testfindSimilarSensors();

    return 0;
}
