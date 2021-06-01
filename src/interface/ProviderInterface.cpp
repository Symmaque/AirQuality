//
// Created by Aurélien on 04/05/2021.
//

#include "ProviderInterface.h"
#include "InterfaceUtils.h"
#include <iostream>
using namespace std;
void ProviderInterface::display() {
    cout << "Bienvenue sur l'interface de l'application pour les fournisseurs" << endl << endl;
}

bool ProviderInterface::authentication() {
    auto logInInfos = getLogInInformations();
    return logInInfos.first == 0 && logInInfos.second == "admin";
}

std::pair<int, std::string> ProviderInterface::getLogInInformations() {
    int id;
    string password;
    cout << "Entrez votre id : " << endl;
    id = InterfaceUtils::inputNumber();
    cout << "Entrez votre mot de passe : " << endl;
    cin >> password;
    return std::make_pair(id, password);
}

void ProviderInterface::chooseAction() {
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
                cout << "Au revoir" << endl;
                return;
            default:
                cout << "Saisissez un nombre entre 1 et 2" << endl;
                choice = InterfaceUtils::inputNumber();
                break;
        }
    }
}

void ProviderInterface::displayMenu() {
    cout << "Veuillez choisir le service souhaité dans le menu déroulant :" << endl << endl;
    cout << "1-Mesurer l’efficacité d’un cleaner" << endl;
    cout << "2-Quitter" << endl;
    cout << endl << "Enter your choice :" << endl;
}
