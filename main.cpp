#include <iostream>
#include <ctime>
#include "Services/Clustering.h"
#include "Model/Sensor.h"
using namespace std;
int foo(int & n){
    return 2*n;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    int i = 5;
    cout << foo(i) << endl;

    auto * sensor = new Sensor(1,2.0,2.0);

    time_t start = time(0);
    tm * startDate = localtime(&start);

    time_t end = time(0);
    tm * endDate = localtime(&end);

    cout << "Start date : " << startDate << endl;
    cout << "End date : " << endDate << endl;


    Clustering::findSimilarSensors(*sensor,*startDate,*endDate);

    return 0;
}
