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

void DataAccess::init()
{
    Reader *reader = new Reader();
    listSensors = reader->readSensor();
    listAttributes = reader->readAttributes();
    listUsers = reader->readUsers();
    /* Warning : you cannot assign with void functions
    listProviders = reader->readProviders();
    listMeasures = reader->readMeasures();
     */
}
