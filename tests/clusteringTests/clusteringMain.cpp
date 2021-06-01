//
// Created by Aurélien on 31/05/2021.
//
#include <iostream>
#include "../../src/data/DataAccess.h"
#include "ClusteringTest.h"
using namespace std;
int main(){
    DataAccess::init("../../resources/tests/");
    if(ClusteringTest::test()){
        cout << "Test for similar sensors successful" << endl;
        exit(0);
    }else{
        cout << "Test for similar sensors failed" << endl;
        exit(1);
    }
}