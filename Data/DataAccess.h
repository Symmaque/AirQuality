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
    User signIn(string id, string password);
    void init();
    vector<User> getListUsers();
    vector<Sensor> getListSensors();
    vector<Provider> getListProviders();
    vector<Measure> getListMeasures();
    vector<Attribute> getListAttribute();

    void setListUsers(const vector<User> &listUsers);

    void setListProviders(const vector<Provider> &listProviders);

protected :
    vector<User> listUsers;
    vector<Provider> listProviders;
}

#endif //AIRQUALITY_DATAACCESS_H
