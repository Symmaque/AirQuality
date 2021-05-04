#include <iostream>
#include <fstream>
#include <string>
#include "Reader.h"
using namespace std;
void readSensors();
void readCleaners();
void readProviders();
void readUsers();

int main()
{
    //readSensor();
    readCleaners();
    readProviders();
    readUsers();
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