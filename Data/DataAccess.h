//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_DATAACCESS_H
#define AIRQUALITY_DATAACCESS_H

#include <iostream>
#include <vector>
#include <map>

#include "../Model/Sensor.h"
#include "../Model/Provider.h"
#include "../Model/Measure.h"
#include "../Model/Attribute.h"
#include "../Model/User.h"
#include "../Model/Individual.h"

using namespace std;
class DataAccess
{

protected:
    static vector<User> listUsers;
    static vector<Sensor> listSensors;
    static vector<Provider> listProviders;
    static vector<Measure> listMeasures;
    static vector<Attribute> listAttributes;
    static vector<Individual> listIndividuals;
    static vector<Cleaner> listCleaners;

public:
    static User signIn(string id, string password);
    static void init();
    static vector<User> *getListUsers();
    static vector<Sensor> *getListSensors();
    static vector<Provider> *getListProviders();
    static vector<Measure> *getListMeasures();
    static vector<Attribute> *getListAttribute();
    static vector<Individual> *getListIndividuals();
    static vector<Cleaner> *getListCleaners();

    static Individual * findIndividual(int id);
    static Sensor * findSensor(int id);

    static void initLists();
    static void setListUsers(const vector<User> &listUsers);
    static void setListProviders(const vector<Provider> &listProviders);
};

#endif //AIRQUALITY_DATAACCESS_H
