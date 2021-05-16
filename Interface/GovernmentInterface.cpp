//
// Created by Aurélien on 04/05/2021.
//

#include "GovernmentInterface.h"
#include <iostream>
using namespace std;

bool GovernmentInterface::authentication() {
    auto logInInfos = getLogInInformations();
    return logInInfos.first == "admin" && logInInfos.second == "admin";
}

std::pair<std::string, std::string> GovernmentInterface::getLogInInformations() {
    string id, password;
    cout << "Enter you id : " << endl;
    cin >> id;
    cout << "Enter you password : " << endl;
    cin >> password;
    return std::make_pair(id,password);
}
void GovernmentInterface::displayMenu(){
    cout << "Veuillez choisir le service souhaité dans le menu déroulant :" << endl << endl;

    cout << "1-Calcul de l’indice ATMO dans un lieu souhaité à un instant donné." << endl;
    cout << "2-Calcul de la moyenne de l’indice ATMO dans un lieu souhaité sur une durée donnée" << endl;
    cout << "3-Mesurer l’efficacité d’un cleaner" << endl;
    cout << "4-Trouver tous les capteurs similaires au capteur de votre choix" << endl;
    cout << "5-Détecter les fraudeurs" << endl;
    cout << "6-Mesurer la fiabilité du capteur de votre choix" << endl;
    cout << "7-Vérifier la cohérence des données de vos capteurs" << endl;
    cout << "8-Quitter" << endl;
    cout << endl << "Enter you choice :" << endl;
}
int inputNumber(){
    string input;
    while (true){
        cin >> input;
        try{
            int res = stoi(input);
            return res;
        } catch (...) {
            cout << "Please enter an integer" << endl;
        }
    }
}

void GovernmentInterface::chooseAction() {
    displayMenu();

    int choice = inputNumber();

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
                cout << "Call detectFraudeurs method" << endl;
                //displayMenu();
                break;
            case 6:
                cout << "Call reliabilitySensor method" << endl;
                //displayMenu();
                break;
            case 7:
                cout << "Call consistencySensorValue method" << endl;
                //displayMenu();
                break;
            case 8:
                cout << "GoodBye" << endl;
                return;
            default:
                cout << "Enter a number between 1 and 8" << endl;
                choice = inputNumber();
                break;
        }
    }

}

void GovernmentInterface::display() {
    cout << "Bienvenue sur l'interface de l'application pour le Gouvernement" << endl << endl;
    chooseAction();
}

