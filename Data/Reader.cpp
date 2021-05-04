#include "Reader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
#include "Reader.h"
#include "../Model/Attribute.h"
#include "../Model/User.h"
#include "../Model/Measure.h"
#include "../Model/Sensor.h"
using namespace std;
/*
static vector<Sensor> readSensor();
static void readCleaners();
static void readProviders();
static void readUsers();
static void readMeasures();
static void readUsers2();
static vector<Attribute> readAttributes();
int main()
{

    readSensor();

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

vector<Sensor> readSensor()
{
    ifstream file("./dataset/sensors.csv");
    string buff;
    int i = 1;
    vector<Sensor> liste;
    if (file.is_open())
    {
        while (getline(file, buff, ';'))
        {
            string sensorId = buff;
            sensorId.erase(0, 6); //Efface "Sensor"
            getline(file, buff, ';');
            double latitude = stod(buff);
            getline(file, buff, ';');
            double longitude = stod(buff);
            cout << i << " : " << sensorId << " " << latitude << " " << longitude << endl;
            Sensor *sen = new Sensor();
            sen->setLatitude(latitude);
            sen->setLongitude(longitude);
            sen->setSensorId(atoi(sensorId.c_str()));
            liste.push_back(*sen);
            i++;
            file.get();
        }
    }
    return liste;
}

void readCleaners()
{
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
            /*
            cout << i << " : " << year << " " << month << " " << day
                 << " -> " << id << " " << type << " " << val << endl;
                 */

            Measure *me = new Measure();
            //me->setAttribute(NULL); //Rajouter le bon attribu (recherche par id?)
            me->setDate(&tmp);
            me->setSensorId(atoi(id.c_str()));
            me->setReliable(true);
            me->setValue(val);
            cout << me->toString() << endl;
            i++;
            file.get(); //Met pointeur au bon endroit
        }
    }
}

vector<Attribute> readAttributes()
{
    ifstream file("./dataset/attributes.csv");
    string buff;
    int i = 1;
    vector<Attribute> liste;
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
            liste.push_back(*att);
            file.get(); //Pourquoi 2? Aucune idée, mais ça marche pas sinon
            file.get();
            i++;
        }
    }
    return liste;
}
