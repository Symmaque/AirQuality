//
// Created by Aurélien on 04/05/2021.
//
#include "DataAccess.h"

#include <iostream>
#include "../Data/Reader.h"

using namespace std;

User DataAccess::signIn(string id, string password) {
    Reader r = new Reader();
    User user = new User();//il faut contructeur par défaut

    vector<User> userList = r.readUsers2();

    //selon la méthode de martin
    //on récupère la liste des utilisateurs pour vérifier
    //si les coordonnées rentrées en paramètre sont bien présents dans notre base de données

    for (User user : listUsers) {
        if (u.getId() == id && u.getPassword() == password) {
            u = new User(id, password);
            return u;
        }
    }
    return null; //si et utilisateur n'existe pas
}

vector<User> &DataAccess::getListUsers() {
    return listUser;
}

vector<Sensor> &DataAccess::getListSensors() {
    return listSensors;
}

vector<Provider> &DataAccess::getListProviders() {
    return listProvider;
}

vector<Measure> &DataAccess::getListMeasures() {
    return listMeasures;
}

vector<Attribute> &DataAccess::getListAttributes() {
    return listAttributes;
}

void DataAccess::init() {
    Reader r = new Reader();
    listUser = r.readUsers();
    listSensors = r.readSensors();
    listProvider = r.readProviders();
    listMeasures = r.readMeasures();
    listAttributes = r.readAttributes();
}