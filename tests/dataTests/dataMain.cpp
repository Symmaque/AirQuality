//
// Created by Aurélien on 01/06/2021.
//
#include "DataTest.h"
#include "../../src/data/DataAccess.h"
#include <iostream>
using namespace std;
int main(){
    DataAccess::init("../../resources/tests/");
    if(DataTest::test()){
        cout << "Test for detect data access successful" << endl;
        exit(0);
    }else{
        cout << "Test for detect data access failed" << endl;
        exit(1);
    }
}