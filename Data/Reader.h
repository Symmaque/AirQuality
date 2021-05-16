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
    static void readSensor();
    static void readCleaners();
    static void readIndividuals();
    static void readProviders();
    static vector<User> readUsers();
    static void readMeasures();
    static void readUsers2();
    static void readAttributes();
};

#endif //READER_H
