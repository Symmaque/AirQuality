#include "Reader.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void Reader::readSensor(const string& path) {
    ifstream file(path);
    string buff;
    int i = 1;
    vector<Sensor> *list = DataAccess::getListSensors();
    if (file.is_open()) {
        while (getline(file, buff, ';')) {
            string sensorId = buff;
            sensorId.erase(0, 6); //Efface "Sensor"
            getline(file, buff, ';');
            double latitude = stod(buff);
            getline(file, buff, ';');
            double longitude = stod(buff);
            Sensor sen(stoi(sensorId), latitude, longitude);

            auto *measurements = DataAccess::getListMeasures();
            auto *sensorMeasures = new vector<Measure *>();
            for (auto &measurement : *measurements) {
                if (measurement.getSensorId() == sen.getSensorId()) {
                    sensorMeasures->push_back(&measurement);
                }
            }
            sen.setMeasures(sensorMeasures);
            list->push_back(sen);
            i++;
            file.get();
        }
    }
    //return list;
}

void Reader::readCleaners(const string& path) {
    ifstream file(path);
    string buff;
    auto *list = DataAccess::getListCleaners();
    int i = 1;
    if (file.is_open()) {
        while (getline(file, buff, ';')) {
            if (buff == "\n")    //EOF
                break;
            int cleanerId = stoi(buff.substr(7));
            getline(file, buff, ';');
            double latitude = stod(buff);
            getline(file, buff, ';');
            double longitude = stod(buff);

            //Lecture date début
            getline(file, buff, ';');
            int year = stoi(buff.substr(0, 4));
            int month = stoi(buff.substr(5, 2));
            int day = stoi(buff.substr(8, 2));
            tm tmp = tm();
            tmp.tm_mday = day;
            tmp.tm_mon = month - 1;
            tmp.tm_year = year - 1900;
            time_t dateBegin = mktime(&tmp);


            //Lecture date fin
            getline(file, buff, ';');
            int year2 = stoi(buff.substr(0, 4));
            int month2 = stoi(buff.substr(5, 2));
            int day2 = stoi(buff.substr(8, 2));
            tmp.tm_mday = day2;
            tmp.tm_mon = month2 - 1;
            tmp.tm_year = year2 - 1900;
            time_t dateEnd = mktime(&tmp);
            Cleaner cleaner(cleanerId, latitude, longitude, dateBegin, dateEnd);
            list->push_back(cleaner);
            file.get();
            i++;
        }
    }
}

void Reader::readProviders(const string& path) {
    ifstream file(path);
    string buff;
    vector<Provider> *list = DataAccess::getListProviders();
    vector<Cleaner> *cleaners = DataAccess::getListCleaners();
    int i = 1;
    if (file.is_open()) {
        while (getline(file, buff, ';')) {
            if (buff == "\n")    //EOF
                break;
            string providerId = buff.substr(8);
            getline(file, buff, ';');
            string cleanerId = buff.substr(7);
            Provider provider;
            provider.setId(stoi(providerId));
            provider.addCleaner(&(*cleaners)[stoi(cleanerId)]);
            file.get();
            list->push_back(provider);

            i++;
        }
    }
}

void Reader::readIndividuals(const string& path){ //Lit les particuliers!
    ifstream file(path);
    string buff;
    int i = 1;
    vector<Individual> *list = DataAccess::getListIndividuals();
    if (file.is_open()) {
        while (getline(file, buff, ';')) {
            if (buff == "\n")
                break;
            string individualId = buff.substr(4, 1);
            //individualId.erase(0, 3); //Enlève "U S E R";
            getline(file, buff, ';');
            string sensorId = buff.substr(6);
            Individual ind;
            ind.setMalicious(false);
            ind.setPoints(0);
            ind.setId(stoi(individualId));

            vector<Sensor> *sensors = DataAccess::getListSensors();
            ind.setSensor(&(*sensors)[stoi(sensorId)]);


            file.get();
            i++;
            list->push_back(ind);
        }
    }
}

void Reader::readAccounts(const string& path){
    ifstream file(path);
    string buff;
    int i = 0;
    auto * userList = DataAccess::getListUsers();
    if (file.is_open()) {
        while (getline(file, buff, ';')) {
            if (buff == "\n")    //EOF
                break;

            string id = buff.substr(0);
            getline(file, buff, ';');
            string password = buff.substr(0);
            User us(stoi(id), password);
            userList->push_back(us);
            i++;
            file.get(); //get the ;
            userList->push_back(us);
        }
    }
}

void Reader::readMeasures(const string& path) {
    ifstream file(path);
    string buff;
    int i = 1;
    vector<Measure> *list = DataAccess::getListMeasures();

    if (file.is_open()) {
        while (getline(file, buff, ';')) //Dégagez le a
        {
            if (buff == "\n")    //EOF
                break;

            //fetch date by time_t
            int year = stoi(buff.substr(0, 4));
            int month = stoi(buff.substr(5, 2));
            int day = stoi(buff.substr(8, 2));
            tm *tmp = new tm();
            tmp->tm_mday = day;
            tmp->tm_mon = month - 1;
            tmp->tm_year = year - 1900;
            time_t date = mktime(tmp);

            //Date date(buff.substr(0,10));

            //Remaining data
            getline(file, buff, ';');
            string id = buff.substr(6);
            getline(file, buff, ';');
            string type = buff;
            getline(file, buff, ';');
            double val = stod(buff);

            vector<Attribute> *attributes = DataAccess::getListAttribute();

            Measure me;// = new Measure();
            //TODO : use map instead of vector of attributes to avoid the loop
            for (auto &att : *attributes) {
                string unit = att.getId();
                if (att.getId() == type) {
                    me.setAttribute(&att);
                    break;
                }
            }
            me.setDate(date);
            me.setSensorId(stoi(id));
            me.setReliable(true);
            me.setValue(val);
            list->push_back(me);
            i++;
            file.get(); //get ;
            delete tmp;
        }
    }
}


void Reader::readUsers2() {

}

void Reader::readAttributes(const string& path) {
    ifstream file(path);
    string buff;
    int i = 1;
    vector<Attribute> *list = DataAccess::getListAttribute();
    if (file.is_open()) {
        getline(file, buff); //Saute première ligne (juste noms des valeurs)
        while (getline(file, buff, ';')) {
            if (buff == "\n")    //EOF
                break;
            string attributeID = buff;
            getline(file, buff, ';');
            string unit = buff;
            getline(file, buff, ';');
            string description = buff;

            auto *att = new Attribute();
            att->setId(attributeID);
            att->setUnit(unit);
            att->setDescription(description);
            list->push_back(*att);
            file.get(); //get ;
            i++;
        }
    }
}