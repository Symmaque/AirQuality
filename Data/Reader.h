#ifndef READER_H
#define READER_H

#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

class Reader
{
public:
    static void readSensor();
    static void readCleaners();
    static void readProviders();
    static void readUsers();
    static void readMeasures();
    static void readUsers2();
};

#endif //READER_H
