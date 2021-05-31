//
// Created by Aurélien on 04/05/2021.
//

#include "GovernmentInterface.h"
#include "InterfaceUtils.h"
#include "IndividualInterface.h"
#include "../Services/Integrity.h"
#include <iostream>
using namespace std;

bool GovernmentInterface::authentication() {
    auto logInInfos = getLogInInformations();
    return logInInfos.first == "admin" && logInInfos.second == "admin";
}

std::pair<std::string, std::string> GovernmentInterface::getLogInInformations() {
    string id, password;
    cout << "Entrez votre id : " << endl;
    cin >> id;
    cout << "Entrez votre mot de passe : " << endl;
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
                cout << "Cette fonctionnalité est en cours de développement..." << endl;
                cout << endl << "Choix :" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
            case 4:
                IndividualInterface::displaySimilarSensors();
                cout << endl << "Choix :" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
            case 5:
                displayDetectUserFraud();
                cout << endl << "Choix :" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
            case 6:
                displayDetectAnyFraud();
                cout << endl << "Choix :" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
            case 7:
                cout << "Cette fonctionnalité est en cours de développement..." << endl;
                cout << endl << "Choix :" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
            case 8:
                cout << "Cette fonctionnalité est en cours de développement..." << endl;
                cout << endl << "Choix :" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
            case 9:
                cout << "Au revoir" << endl;
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
    Individual * individual = DataAccess::findIndividual(userId);

    while(individual == nullptr){
        cout << "Cet utilisateur n'existe pas" << endl;
        cout << "Entrez l'identifiant d'un utilisateur" << endl;
        cin >> userId;
        individual = DataAccess::findIndividual(userId);
    }

    cout << "L'utilisateur demandé est : " << userId << ", avec le capteur : " << (*individual).getSensor()->getSensorId() << endl;
    bool fraud = Integrity::detectUserFraud(*individual);
    cout << " Fraude = " << fraud << endl;
}

void GovernmentInterface::displayDetectAnyFraud() {
    cout << "Détection des fraudeurs..." << endl;
    vector<Individual> fraud = Integrity::detectFraud();
    for(const Individual& individual : fraud) {
        cout << "Utilisateur frauduleux trouvé : " << individual << endl;
    }

}