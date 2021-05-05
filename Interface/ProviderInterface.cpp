//
// Created by Aurélien on 04/05/2021.
//

#include "ProviderInterface.h"
#include <iostream>
using namespace std;
void ProviderInterface::display() {
    cout << "Bienvenue sur l'interface de l'application pour les fournisseurs" << endl << endl;
}

bool ProviderInterface::authentication() {
    auto logInInfos = getLogInInformations();
    return logInInfos.first == "admin" && logInInfos.second == "admin";
}

std::pair<std::string, std::string> ProviderInterface::getLogInInformations() {
    string id, password;
    cout << "Enter you id : " << endl;
    cin >> id;
    cout << "Enter you password : " << endl;
    cin >> password;
    return std::make_pair(id,password);
}

void ProviderInterface::chooseAction() {
    int choice = 0;
    displayMenu();

    cin >> choice;  //TODO : safe input

    while(true) {
        switch (choice) {
            case 1:
                cout << "Call efficaciteCleaner method" << endl;
                //displayMenu();
                cin >> choice;
                break;
            case 2:
                cout << "GoodBye" << endl;
                return;
            default:
                cout << "Enter a valid number" << endl;
                cin >> choice;
                break;
        }
    }
}

void ProviderInterface::displayMenu() {
    cout << "Veuillez choisir le service souhaité dans le menu déroulant :" << endl << endl;
    cout << "1-Mesurer l’efficacité d’un cleaner" << endl;
    cout << "2-Quitter" << endl;
    cout << endl << "Enter you choice :" << endl;
}
