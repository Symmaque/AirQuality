#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
#include "Reader.h"
#include "../Model/Attribute.h"
#include "../Model/User.h"
#include "../Model/Provider.h"
using namespace std;

void readSensors(); //Le header marche pas?
void readCleaners();
void readProviders();
void readMeasures();
void readAttributes();
//void readUsers();


/*
int main()
{
    readSensors();
    cout << "------" << endl;
    readCleaners();
    cout << "------" << endl;
    readProviders();
    cout << "------" << endl;
    //readUsers();
    cout << "------" << endl;
    readMeasures();
    cout << "------" << endl;
    readAttributes();
    cout << "done";
    return 0;
}
 */

void readSensors()
{
    //File pointer
    ifstream file("./dataset/sensors.csv");
    string buff;
    int i = 1;
    if (file.is_open())
    {
        while (getline(file, buff, ';'))
        {
            string sensorId = buff;
            getline(file, buff, ';');
            double latitude = stod(buff);
            getline(file, buff, ';');
            double longitude = stod(buff);
            cout << i << " : " << sensorId << " " << latitude << " " << longitude << endl;
            i++;
            file.get();
        }
    }
}

void readCleaners()
{
    //File pointer
    ifstream file("./dataset/cleaners.csv");
    string buff;
    int i = 1;
    if (file.is_open())
    {
        while (getline(file, buff, ';'))
        {
            string cleanerId = buff;
            getline(file, buff, ';');
            double latitude = stod(buff);
            getline(file, buff, ';');
            double longitude = stod(buff);

            //Lecture date début
            getline(file, buff, ';');
            int year = atoi(buff.substr(0, 4).c_str());
            int month = atoi(buff.substr(5, 2).c_str());
            int day = atoi(buff.substr(8, 2).c_str());
            tm tmp = tm();
            tmp.tm_mday = day;
            tmp.tm_mon = month - 1;
            tmp.tm_year = year - 1900;
            time_t dateBegin = mktime(&tmp);

            //Lecture date fin
            getline(file, buff, ';');
            int year2 = atoi(buff.substr(0, 4).c_str());
            int month2 = atoi(buff.substr(5, 2).c_str());
            int day2 = atoi(buff.substr(8, 2).c_str());
            tmp.tm_mday = day;
            tmp.tm_mon = month - 1;
            tmp.tm_year = year - 1900;
            time_t dateEnd = mktime(&tmp);

            cout << i << " : " << cleanerId << " " << latitude << " " << longitude
                 << " " << year << "/" << month << "/" << day << " - "
                 << year2 << "/" << month2 << "/" << day2 << endl;

            file.get();
            i++;
        }
    }
}

void readProviders()
{
    //File pointer
    ifstream file("./dataset/providers.csv");
    string buff;
    int i = 1;
    if (file.is_open())
    {
        while (getline(file, buff, ';'))
        {
            string providerId = buff;
            getline(file, buff, ';');
            string cleanerId = buff;
            //Créer obj ici
            cout << i << " : " << providerId << " " << cleanerId << endl;
            file.get();
            i++;
        }
    }
}

void readUsers()
{
    //File pointer
    ifstream file("./dataset/users.csv");
    string buff;
    int i = 0;
    if (file.is_open())
    {
        while (getline(file, buff, ';'))
        {
            string userId = buff;
            getline(file, buff, ';');
            string password = buff;
            //cout << i << " : " << userId << " " << sensorId << endl;
            User *us = new User(atoi(userId.c_str()), password);
            i++;
            file.get();
        }
    }
}

void readMeasures()
{
    //File pointer
    ifstream file("./dataset/measurements.csv");
    string buff;
    int i = 1;
    if (file.is_open())
    {
        while (getline(file, buff, ';') && i < 10) //Dégagez le a
        {
            //Récupère date en time_t
            int year = atoi(buff.substr(0, 4).c_str());
            int month = atoi(buff.substr(5, 2).c_str());
            int day = atoi(buff.substr(8, 2).c_str());
            tm tmp = tm();
            tmp.tm_mday = day;
            tmp.tm_mon = month - 1;
            tmp.tm_year = year - 1900;
            time_t date = mktime(&tmp);

            //Reste des données
            getline(file, buff, ';');
            string id = buff;
            getline(file, buff, ';');
            string type = buff;
            getline(file, buff, ';');
            double val = stod(buff);
            cout << i << " : " << year << " " << month << " " << day
                 << " -> " << id << " " << type << " " << val << endl;

            //Créer objet ici
            i++;
            file.get(); //Met pointeur au bon endroit
        }
    }
}
void readAttributes()
{
    //File pointer
    ifstream file("./dataset/attributes.csv");
    string buff;
    int i = 1;
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
            //cout << i << " : " << attributeID << " " << unit << " " << description << endl;
            Attribute *att = new Attribute();
            att->setUnit(unit);
            att->setDescription(description);
            cout << i << " : " << att->toString() << endl;
            file.get(); //Pourquoi 2? Aucune idée, mais ça marche pas sinon
            file.get();
            i++;
        }
    }
}
