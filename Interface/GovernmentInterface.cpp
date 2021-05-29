//
// Created by Aurélien on 04/05/2021.
//

#include "GovernmentInterface.h"
#include "InterfaceUtils.h"
#include "../Services/Integrity.h"
#include <iostream>
using namespace std;

bool GovernmentInterface::authentication() {
    auto logInInfos = getLogInInformations();
    return logInInfos.first == "admin" && logInInfos.second == "admin";
}

std::pair<std::string, std::string> GovernmentInterface::getLogInInformations() {
    string id, password;
    cout << "Enter your id : " << endl;
    cin >> id;
    cout << "Enter your password : " << endl;
    cin >> password;
    return std::make_pair(id,password);
}
void GovernmentInterface::displayMenu(){
    cout << "Veuillez choisir le service souhaité dans le menu déroulant :" << endl << endl;

    cout << "1-Calcul de l’indice ATMO dans un lieu souhaité à un instant donné." << endl;
    cout << "2-Calcul de la moyenne de l’indice ATMO dans un lieu souhaité sur une durée donnée" << endl;
    cout << "3-Mesurer l’efficacité d’un cleaner" << endl;
    cout << "4-Trouver tous les capteurs similaires au capteur de votre choix" << endl;
    cout << "5-Détecter si un utilisateur fraude" << endl;
    cout << "6-Détecter les fraudeurs" << endl;
    cout << "7-Mesurer la fiabilité du capteur de votre choix" << endl;
    cout << "8-Vérifier la cohérence des données de vos capteurs" << endl;
    cout << "9-Quitter" << endl;
    cout << endl << "Enter your choice :" << endl;
}

void GovernmentInterface::chooseAction() {
    displayMenu();

    int choice = InterfaceUtils::inputNumber();

    while(true) {
        switch (choice) {
            case 1:
                cout << "Call indiceAtmo method" << endl;
                //displayMenu();
                break;
            case 2:
                cout << "Call meanIndiceAtmo method" << endl;
                //displayMenu();
                break;
            case 3:
                cout << "Call efficaciteCleaner method" << endl;
                //displayMenu();
                break;
            case 4:
                cout << "Call similarCaptors method" << endl;
                //displayMenu();
                break;
            case 5:
                cout << "Call detectUserFraud method" << endl;
                displayDetectUserFraud();
                cout << endl << "Enter your choice :" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
            case 6:
                cout << "Call detectAnyFraud method" << endl;
                displayDetectAnyFraud();
                cout << endl << "Enter your choice :" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
            case 7:
                cout << "Call reliabilitySensor method" << endl;
                //displayMenu();
                break;
            case 8:
                cout << "Call consistencySensorValue method" << endl;
                //displayMenu();
                break;
            case 9:
                cout << "GoodBye" << endl;
                return;
            default:
                cout << "Enter a number between 1 and 9" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
        }
    }

}

void GovernmentInterface::display() {
    cout << "Bienvenue sur l'interface de l'application pour le Gouvernement" << endl << endl;
    chooseAction();
}

void GovernmentInterface::displayDetectUserFraud() {
    cout << "Entrez l'identifiant d'un utilisateur" << endl;
    int userId;
    cin >> userId;
    Individual & individual = DataAccess::findIndividual(userId);
    cout << "Found user asked = " << userId << " sensor = " << individual.getSensor()->getSensorId() << endl;
    bool fraud = Integrity::detectUserFraud(individual);
    cout << " Fraud = " << fraud << endl;
}

void GovernmentInterface::displayDetectAnyFraud() {
    cout << "Détection des fraudeurs..." << endl;
    vector<Individual> fraud = Integrity::detectFraud();
    for(const Individual& individual : fraud) {
        cout << " Malicious user found " << individual << endl;
    }

}