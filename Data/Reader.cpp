#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
#include "Reader.h"
using namespace std;
void readMeasures();
void readAttributes();
void readUsers();
int main()
{
    /*
    readSensor();
    readCleaners();
    readProviders();
    */
    //readUsers();
    //readMeasures();
    readAttributes();
    cout << "done";
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
    int i = 0;
    if (file.is_open())
    {
        while (getline(file, buff, ';'))
        {
            string userId = buff;
            getline(file, buff, ';');
            string sensorId = buff;
            cout << i << " : " << userId << " " << sensorId << endl;
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
            cout << year << " " << month << " " << day << endl;
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
            cout << i << " : " << id << " " << type << " " << val << endl;

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
            cout << i << " : " << attributeID << " " << unit << " " << description << endl;
            //Créer l'objet ici
            file.get(); //Pourquoi 2? Aucune idée, mais ça marche pas sinon
            file.get();
            i++;
        }
    }
}
