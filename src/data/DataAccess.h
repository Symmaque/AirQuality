//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_DATAACCESS_H
#define AIRQUALITY_DATAACCESS_H

#include <iostream>
#include <vector>
#include <map>

#include "../model/Sensor.h"
#include "../model/Provider.h"
#include "../model/Measure.h"
#include "../model/Attribute.h"
#include "../model/User.h"
#include "../model/Individual.h"

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
    static void init(const string& folder);
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

    static void removeSensor(Sensor * sensor);
    static void removeSensor(int id);
    static void removeMeasures(int sensorId);
};

#endif //AIRQUALITY_DATAACCESS_H
