//
// Created by allan guigal on 18/05/2021.
//

#include "InterfaceUtils.h"
#include <iostream>
using namespace std;

int InterfaceUtils::inputNumber() {
    string input;
    while (true){
        cin >> input;
        try{
            int res = stoi(input);
            return res;
        } catch (...) {
            cin.clear();
            cout << "Nombre invalide veuillez essayer à nouveau :" << endl;
        }
    }
}