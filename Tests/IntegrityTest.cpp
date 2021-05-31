//
// Created by allan guigal on 31/05/2021.
//

#include "IntegrityTest.h"
#include "../src/services/Integrity.h"

void IntegrityTest::test() {

    //12 and 13 sensors are frauding
    Individual individual2 = DataAccess::findIndividual(2);
    Individual individual3 = DataAccess::findIndividual(3);

    if(!Integrity::detectUserFraud(individual2)) {
        cout << "Test failed individual 2 is frauding" << endl;
    }
    if(!Integrity::detectUserFraud(individual3)) {
        cout << "Test failed individual 3 is frauding" << endl;
    }

    auto frauders = Integrity::detectFraud();

    if(frauders.size() != 2) {
        cout << "Test failed size of the frauders must be 2" << endl;
    }

    if(find(frauders.begin(), frauders.end(), individual2) == frauders.end()) {
        cout << "Test failed individual 2 in frauders list" << endl;
    }
    if(find(frauders.begin(), frauders.end(), individual3) == frauders.end()) {
        cout << "Test failed individual 3 in frauders list" << endl;
    }

}