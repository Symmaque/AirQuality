#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Reader.h"
using namespace std;
void readMeasures();
int main()
{
    /*
    readSensor();
    readCleaners();
    readProviders();
    readUsers();
    */
    readMeasures();
    return 0;
}

void readSensors()
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

void readCleaners()
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

void readProviders()
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

void readUsers()
{
    //File pointer
    ifstream file("./dataset/users.csv");
    string buff;
    if (file.is_open())
    {
        while (getline(file, buff, ';'))
        {
            cout << buff << ";";
        }
    }
}

void readMeasures()
{
    //File pointer
    ifstream file("./dataset/measurements.csv");
    string buff;
    bool a = true;
    if (file.is_open())
    {
        while (getline(file, buff, ';') && a)
        {
            int year = atoi(buff.substr(0, 4).c_str());
            int month = atoi(buff.substr(5, 2).c_str());
            //int day = atoi(buff.substr(8, 2).c_str());
            cout << month << ";";
            a = false;
        }
    }
}