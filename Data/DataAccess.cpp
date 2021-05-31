//
// Created by Aurélien on 04/05/2021.
//
#include "DataAccess.h"

#include <iostream>
#include "../Data/Reader.h"

using namespace std;

vector<User> DataAccess::listUsers = {};
vector<Sensor> DataAccess::listSensors = {};
vector<Attribute> DataAccess::listAttributes = {};
vector<Measure> DataAccess::listMeasures = {};
vector<Provider> DataAccess::listProviders = {};
vector<Individual> DataAccess::listIndividuals = {};
vector<Cleaner> DataAccess::listCleaners = {};

User DataAccess::signIn(string id, string password)
{
    /*
    User * user = new User();//il faut contructeur par défaut
    vector<User> userList = Reader::readUsers2();

    //selon la méthode de martin
    //on récupère la liste des utilisateurs pour vérifier
    //si les coordonnées rentrées en paramètre sont bien présents dans notre base de données

    for (User user : listUsers) {
        if (user.getId() == id && user.getPassword() == password) {
            user = new User(id, password);
            return user;
        }
    }
    return nullptr; //si et utilisateur n'existe pas
     */
    return *new User;
}

vector<User> *DataAccess::getListUsers()
{
    return &listUsers;
}

vector<Sensor> *DataAccess::getListSensors()
{
    return &listSensors;
}

vector<Provider> *DataAccess::getListProviders()
{
    return &listProviders;
}

vector<Measure> *DataAccess::getListMeasures()
{
    return &listMeasures;
}

vector<Attribute> *DataAccess::getListAttribute()
{
    return &listAttributes;
}

void DataAccess::init(){
    Reader::readAttributes();
    Reader::readMeasures();
    Reader::readSensor();
    Reader::readCleaners();
    Reader::readIndividuals();
    Reader::readProviders();
    //listUsers = Reader::readUsers(); file "accounts" needed

}

vector<Individual> *DataAccess::getListIndividuals() {
    return &listIndividuals;
}

vector<Cleaner> *DataAccess::getListCleaners() {
    return &listCleaners;
}

Individual * DataAccess::findIndividual(int id) {
    for(auto & it : listIndividuals) {
        if(it.getId() == id) return &it;
    }
    return nullptr;
}

Sensor * DataAccess::findSensor(int id) {
    for(auto & it : listSensors) {
        if(it.getSensorId() == id) return &it;
    }
    return nullptr;
}
