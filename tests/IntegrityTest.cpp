//
// Created by allan guigal on 31/05/2021.
//

#include "IntegrityTest.h"
#include "../src/services/Integrity.h"
#include <algorithm>
using namespace std;
bool IntegrityTest::test() {


    //first test : individual with invalid id should not be fetched

    //12 and 13 sensors are frauding
    Individual individual2 = *DataAccess::findIndividual(2);
    Individual individual3 = *DataAccess::findIndividual(3);

    if(!Integrity::detectUserFraud(individual2)) {
        cout << "Test failed individual 2 is frauding" << endl;
        return false;
    }

    if(!Integrity::detectUserFraud(individual3)) {
        cout << "Test failed individual 3 is frauding" << endl;
        return false;
    }

    auto frauders = Integrity::detectFraud();

    cout << "Frauders list : " << endl;
    for(auto f : frauders) {
        cout << f << endl;
    }

    cout << "Size " << frauders.size() << endl;
    if(frauders.size() != 2) {
        cout << "Test failed size of the frauders must be 2" << endl;
        return false;
    }

    if(find(frauders.begin(), frauders.end(), individual2) == frauders.end()) {
        cout << "Test failed individual 2 in frauders list" << endl;
        return false;
    }
    if(find(frauders.begin(), frauders.end(), individual3) == frauders.end()) {
        cout << "Test failed individual 3 in frauders list" << endl;
        return false;
    }
    return true;

}