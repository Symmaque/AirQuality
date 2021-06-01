//
// Created by Aurélien on 01/06/2021.
//

#include "StatsTest.h"
#include "../src/data/DataAccess.h"
#include <iostream>
using namespace std;
int main(){
    DataAccess::init("../../resources/tests/");
    if(StatsTest::test()){
        cout << "Test for stats tests successful" << endl;
        exit(0);
    }else{
        cout << "Test for stats tests failed" << endl;
        exit(1);
    }
}