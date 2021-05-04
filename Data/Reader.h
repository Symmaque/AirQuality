//---------- Interface de la classe <Liste> (fichier Liste.h) ----------------
#include <iostream>
#include <fstream>
#include <string>
#if !defined(READER_H)
#define READER_H

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

#endif // READER_H
