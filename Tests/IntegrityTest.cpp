//
// Created by allan guigal on 31/05/2021.
//

#include "IntegrityTest.h"
#include "../Services/Integrity.h"
#include <algorithm>
using namespace std;
void IntegrityTest::test() {

    //12 and 13 sensors are frauding
    Individual individual12 = DataAccess::findIndividual(12);
    Individual individual13 = DataAccess::findIndividual(13);

    if(!Integrity::detectUserFraud(individual12)) {
        cout << "Test failed individual 12 is frauding" << endl;
    }
    if(!Integrity::detectUserFraud(individual13)) {
        cout << "Test failed individual 13 is frauding" << endl;
    }

    auto frauders = Integrity::detectFraud();

    if(frauders.size() != 2) {
        cout << "Test failed size of the frauders must be 2" << endl;
    }
    cout << "FRAUDERS ###################################" << endl;
    for(const auto& frauder : frauders){
        cout << frauder << endl;
    }
    cout << " ###################################" << endl;
    if(find(frauders.begin(), frauders.end(), individual12) == frauders.end()) {
        cout << "Test failed individual 12 in frauders list" << endl;
    }
    if(find(frauders.begin(), frauders.end(), individual13) == frauders.end()) {
        cout << "Test failed individual 13 in frauders list" << endl;
    }

}