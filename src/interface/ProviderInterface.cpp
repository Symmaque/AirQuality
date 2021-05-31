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
    return logInInfos.first == "admin" && logInInfos.second == "admin";
}

std::pair<std::string, std::string> ProviderInterface::getLogInInformations() {
    string id, password;
    cout << "Enter your id : " << endl;
    cin >> id;
    cout << "Enter your password : " << endl;
    cin >> password;
    return std::make_pair(id, password);
}

void ProviderInterface::chooseAction() {
    displayMenu();
    int choice = InterfaceUtils::inputNumber();

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
                cout << "Enter a number between 1 and 2" << endl;
                choice = InterfaceUtils::inputNumber();
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
