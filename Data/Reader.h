#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
#include "DataAccess.h"
#include "Reader.h"
#include "../Model/Attribute.h"
#include "../Model/User.h"
#include "../Model/Measure.h"
#include "../Model/Sensor.h"

class Reader
{
public:
    static vector<Sensor> readSensor();
    static vector<Cleaner> readCleaners();
    static vector<Individual> readIndividuals();
    static vector<Provider> readProviders();
    static vector<User> readUsers();
    static vector<Measure> readMeasures();
    static void readUsers2();
    static vector<Attribute> readAttributes();
};

#endif //READER_H
