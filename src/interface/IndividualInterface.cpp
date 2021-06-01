//
// Created by Aurélien on 04/05/2021.
//

#include "IndividualInterface.h"
#include "InterfaceUtils.h"
#include "../data/DataAccess.h"
#include "../services/Clustering.h"
#include <iostream>

using namespace std;

void IndividualInterface::display() {
    cout << "Bienvenue sur l'interface de l'application pour les individuals" << endl
         << endl;
    chooseAction();
}

bool IndividualInterface::authentication() {
    auto logInInfos = getLogInInformations();
    return logInInfos.first == "admin" && logInInfos.second == "admin";
}

std::pair<std::string, std::string> IndividualInterface::getLogInInformations() {
    string id, password;
    cout << "Entrez votre id : " << endl;
    cin >> id;
    cout << "Entrez votre mot de passe : " << endl;
    cin >> password;
    return std::make_pair(id, password);
}

void IndividualInterface::chooseAction() {

    displayMenu();

    int choice = InterfaceUtils::inputNumber();

    while (true) {
        switch (choice) {
            case 1:
                cout << "Cette fonctionnalité est en cours de développement..." << endl;
                cout << endl << "Choix :" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
            case 2:
                cout << "Cette fonctionnalité est en cours de développement..." << endl;
                cout << endl << "Choix :" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
            case 3:
                IndividualInterface::displaySimilarSensors();
                cout << endl << "Choix :" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
            case 4:
                cout << "Au revoir" << endl;
                return;
            default:
                cout << "Saisissez un nombre entre 1 et 4" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
        }
    }
}

void IndividualInterface::displayMenu() {
    cout << "Veuillez choisir le service souhaité dans le menu déroulant :" << endl << endl;

    cout << "1-Calcul de l’indice ATMO dans un lieu souhaité à un instant donné." << endl;
    cout << "2-Calcul de la moyenne de l’indice ATMO dans un lieu souhaité sur une durée donnée" << endl;
    cout << "3-Trouver tous les capteurs similaires au capteur de votre choix" << endl;
    cout << "4-Quitter" << endl;
    cout << endl
         << "Choix :" << endl;
}


void IndividualInterface::displaySimilarSensors() {
    cout << "Veuillez entrer l'id du capteur a etudier" << endl;
    int id = InterfaceUtils::inputNumber();
    Sensor *s = DataAccess::findSensor(id);
    while(s == nullptr){
        cout << "Id de capteur invalide" << endl;
        cout << "Veuillez entrer l'id du capteur a etudier" << endl;
        cin >> id;
        s = DataAccess::findSensor(id);
    }

    int startYear;
    int startMonth;
    int startDay;
    int endYear;
    int endMonth;
    int endDay;

    cout << "Veuillez entrer l'annee de début" << endl;
    startYear = InterfaceUtils::inputNumber();
    if (startYear != 2019) {
        cout << "Nous n'avons actuellement que des mesures pour l'année 2019 " << endl;
    }
    while (startYear < 1 || startYear > 2021) {
        cout << "Veuillez entrer des données valides" << endl;
        cout << "Veuillez entrer l'année' de début" << endl;
        startYear = InterfaceUtils::inputNumber();
    }

    cout << "Veuillez entrer le mois de début" << endl;
    startMonth = InterfaceUtils::inputNumber();
    while (startMonth < 1 || startMonth > 12) {
        cout << "Veuillez entrer des données valides" << endl;
        cout << "Veuillez entrer le mois de début" << endl;
        startMonth = InterfaceUtils::inputNumber();
    }

    cout << "Veuillez entrer le jour de début" << endl;
    startDay = InterfaceUtils::inputNumber();
    while (startDay < 1 || startDay > 31) {
        cout << "Veuillez entrer des données valides" << endl;
        cout << "Veuillez entrer le jour de début" << endl;
        startDay = InterfaceUtils::inputNumber();
    }

    cout << "Veuillez entrer l'annee de fin" << endl;
    endYear = InterfaceUtils::inputNumber();
    if (endYear < startYear){
        cout << "Attention, la date de fin doit etre posterieure à la date de debut" << endl;
        endYear = InterfaceUtils::inputNumber();
    }
    if (endYear != 2019) {
        cout << "Nous n'avons actuellement que des mesures pour l'année 2019 " << endl;
    }
    while (endYear < 1 || endYear > 2021) {
        cout << "Veuillez entrer des données valides" << endl;
        cout << "Veuillez entrer l'année' de fin" << endl;
        endYear = InterfaceUtils::inputNumber();
    }

    cout << "Veuillez entrer le mois de fin" << endl;
    endMonth = InterfaceUtils::inputNumber();
    while (endMonth < 1 || endMonth > 12) {
        cout << "Veuillez entrer des données valides" << endl;
        cout << "Veuillez entrer le mois de fin" << endl;
        endMonth = InterfaceUtils::inputNumber();
    }

    cout << "Veuillez entrer le jour de fin" << endl;
    endDay = InterfaceUtils::inputNumber();
    while (endDay < 1 || endDay > 31) {
        cout << "Veuillez entrer des données valides" << endl;
        cout << "Veuillez entrer le jour de fin" << endl;
        endDay = InterfaceUtils::inputNumber();
    }

    tm *tmp1 = new tm();
    tm *tmp2 = new tm();

    tmp1->tm_mday = startDay;
    tmp1->tm_mon = startMonth;
    tmp1->tm_year = startDay;

    tmp2->tm_mday = endDay;
    tmp2->tm_mon = endMonth;
    tmp2->tm_year = endYear;

    vector<Sensor *> *result = Clustering::findSimilarSensors(*s, mktime(tmp1), mktime(tmp2));
    //si result = nullptr, soit a
    //si result est vide,

    if (result == nullptr) {
        cout << "Une erreur est survenue, veuillez réessayer plus tard" << endl;
    } else if ((*result).empty()) {
        cout << "Aucun capteur similaire sur cette période" << endl;
    } else {
        cout << "liste des capteurs similaires :" << endl;
        for (int i = 0; i < 5; i++) {
            cout << *((*result)[i]) << endl;
        }
    }

}
