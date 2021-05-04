#include <iostream>
#include <fstream>
#include <string>
#include "Reader.h"
using namespace std;
void readSensor();
void readCleaner();
void readProvider();

int main()
{
    //readSensor();
    readCleaner();
    readProvider();
    return 0;
}

void readSensor()
{
    //File pointer
    ifstream file("./dataset/sensors.csv");
    string buff;
    if (file.is_open())
    {
        while (getline(file, buff, ';'))
        {
            cout << buff << ";";
        }
    }
}

void readCleaner()
{
    //File pointer
    ifstream file("./dataset/cleaners.csv");
    string buff;
    if (file.is_open())
    {
        while (getline(file, buff, ';'))
        {
            cout << buff << ";";
        }
    }
}

void readProvider()
{
    //File pointer
    ifstream file("./dataset/providers.csv");
    string buff;
    if (file.is_open())
    {
        while (getline(file, buff, ';'))
        {
            cout << buff << ";";
        }
    }
}