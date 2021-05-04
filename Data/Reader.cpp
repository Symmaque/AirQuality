#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
#include "Reader.h"
using namespace std;
void readMeasures();
void readAttributes();
int main()
{
    /*
    readSensor();
    readCleaners();
    readProviders();
    readUsers();
    */
    readMeasures();
    readAttributes();
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
        while (getline(file, buff, ';') && a) //Dégagez le a
        {
            //Récupère date en time_t
            int year = atoi(buff.substr(0, 4).c_str());
            int month = atoi(buff.substr(5, 2).c_str());
            int day = atoi(buff.substr(8, 2).c_str());
            cout << year << " " << month << " " << day << endl;
            tm tmp = tm();
            tmp.tm_mday = day;
            tmp.tm_mon = month - 1;
            tmp.tm_year = year - 1900;
            time_t date = mktime(&tmp);
            getline(file, buff, ';');
            string id = buff;
            getline(file, buff, ';');
            string type = buff;
            getline(file, buff, ';');
            double val = stod(buff);
            cout << id << " " << type << " " << val << endl;

            a = false;
        }
    }
}
void readAttributes()
{
    //File pointer
    ifstream file("./dataset/attributes.csv");
    string buff;
    if (file.is_open())
    {
        getline(file, buff); //Saute première ligne (juste noms des valeurs)
        while (getline(file, buff, ';'))
        {
            string attributeID = buff;
            getline(file, buff, ';');
            string unit = buff;
            getline(file, buff, ';');
            string description = buff;
            cout << attributeID << ";";
            //Créer l'objet ici
        }
    }
}
