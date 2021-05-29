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
    static void readSensor(const string& path);
    static void readCleaners(const string& path);
    static void readIndividuals(const string& path);
    static void readProviders(const string& path);
    static vector<User> readUsers();
    static void readMeasures(const string& path);
    static void readUsers2();
    static void readAttributes(const string& path);
};

#endif //READER_H
