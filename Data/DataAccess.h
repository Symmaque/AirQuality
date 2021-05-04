//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_DATAACCESS_H
#define AIRQUALITY_DATAACCESS_H


#include <iostream>
#include <vector>


#include "../Model/Sensor.h"
#include "../Model/Provider.h"
#include "../Model/Measure.h"
#include "../Model/Attribute.h"
#include "../Model/User.h"

using namespace std;
class DataAccess{

public:
    static User signIn(string id, string password);
    void init();
    static vector<User> & getListUsers();
    static vector<Sensor> & getListSensors();
    static vector<Provider> & getListProviders();
    static vector<Measure> & getListMeasures();
    static vector<Attribute> & getListAttribute();

    static void setListUsers(const vector<User> &listUsers);

    static void setListProviders(const vector<Provider> &listProviders);

protected :
    static vector<User> listUsers;
    static vector<Provider> listProviders;

}

#endif //AIRQUALITY_DATAACCESS_H
