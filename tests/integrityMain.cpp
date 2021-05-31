//
// Created by Aurélien on 29/05/2021.
//

#include "../src/data/DataAccess.h"
#include "IntegrityTest.h"
#include <iostream>
using namespace std;

int main(){
    DataAccess::init("../resources/tests/");
    if(IntegrityTest::test()){
        cout << "Test for detect User fraud successful" << endl;
        exit(0);
    }else{
        cout << "Test for detect User fraud failed" << endl;
        exit(1);
    }
}