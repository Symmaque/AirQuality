//
// Created by Aurélien on 04/05/2021.
//

#include "IndividualInterface.h"
#include "InterfaceUtils.h"
#include <iostream>
using namespace std;
void IndividualInterface::display() {
    cout << "Bienvenue sur l'interface de l'application pour les individuals" << endl << endl;
    chooseAction();
}

bool IndividualInterface::authentication() {
    auto logInInfos = getLogInInformations();
    return logInInfos.first == "admin" && logInInfos.second == "admin";
}

std::pair<std::string, std::string> IndividualInterface::getLogInInformations() {
    string id, password;
    cout << "Enter you id : " << endl;
    cin >> id;
    cout << "Enter you password : " << endl;
    cin >> password;
    return std::make_pair(id,password);
}

void IndividualInterface::chooseAction() {

    displayMenu();

    int choice = InterfaceUtils::inputNumber();

    while(true) {
        switch (choice) {
            case 1:
                cout << "Call indiceAtmo method" << endl;
                //displayMenu();
                cin >> choice;
                break;
            case 2:
                cout << "Call meanIndiceAtmo method" << endl;
                //displayMenu();
                cin >> choice;
                break;
            case 3:
                cout << "Call similarCaptors method" << endl;
                //displayMenu();
                cin >> choice;
                break;
            case 4:
                cout << "GoodBye" << endl;
                return;
            default:
                cout << "Enter a number between 1 and 4" << endl;
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
    cout << endl << "Enter your choice :" << endl;
}
