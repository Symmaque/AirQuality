//
// Created by Aurélien on 29/05/2021.
//

#include "ClusteringTest.h"
#include "IntegrityTest.h"
#include "../src/services/Integrity.h"
#include "../src/services/Clustering.h"
#include <algorithm>
using namespace std;
bool ClusteringTest::test() {
    auto * sensors = DataAccess::getListSensors();

    auto sensor1 = (*sensors)[0];

    tm *tmp = new tm();
    tmp->tm_mday = 30;
    tmp->tm_mon = 12 - 1;
    tmp->tm_year = 2019 - 1900;
    time_t start = mktime(tmp);

    tmp->tm_mday = 31;
    tmp->tm_mon = 12 - 1;
    tmp->tm_year = 2019 - 1900;
    time_t end = mktime(tmp);

    cout << "Start : " << start << endl;
    cout << "End : " << end << endl;
    auto * similarSensors = Clustering::findSimilarSensors(sensor1,start,end);
    if(similarSensors == nullptr){
        cerr << "similarSensor is nullptr " << endl;
        return false;
    }

    cout << "Dix premiers capteurs similaires : ################################################" << endl << endl;
    for(int i = 0; i < 10 && i < similarSensors->size(); i++){
        cout << *(*similarSensors)[i] << endl;
    }
    delete similarSensors;
    return true;

}