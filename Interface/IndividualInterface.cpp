//
// Created by Aurélien on 04/05/2021.
//

#include "IndividualInterface.h"
#include "InterfaceUtils.h"
#include "../Data/DataAccess.h"
#include "../Services/Clustering.h"
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
    cout << "Enter you id : " << endl;
    cin >> id;
    cout << "Enter you password : " << endl;
    cin >> password;
    return std::make_pair(id, password);
}

void IndividualInterface::chooseAction() {

    displayMenu();

    int choice = InterfaceUtils::inputNumber();

    while (true)
    {
        switch (choice)
        {
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
            IndividualInterface::displaySimilarSensors();
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
    cout << endl
         << "Enter you choice :" << endl;
}


void IndividualInterface::displaySimilarSensors()
{
    cout << "Veuillez entrer l'id du capteur a etudier" << endl;
    int id;
    cin >> id;
    Sensor & s = DataAccess::findSensor(id);

    int startYear;
    int startMonth;
    int startDay;
    int endYear;
    int endMonth;
    int endDay;

    cout << "Veuillez entrer l'annee de début" << endl;
    cin >> startYear;
    cout << "Veuillez entrer le mois de début" << endl;
    cin >> startMonth;
    cout << "Veuillez entrer le jour de début" << endl;
    cin >> startDay;
    
    cout << "Veuillez entrer le jour de fin" << endl;
    cin >> endYear;
    cout << "Veuillez entrer la date de fin" << endl;
    cin >> endMonth;
    cout << "Veuillez entrer la date de fin" << endl;
    cin >> endDay;

    tm *tmp1 = new tm();
    tm *tmp2 = new tm();

    tmp1->tm_mday = startDay;
    tmp1->tm_mon = startMonth;
    tmp1->tm_year = startDay;

    tmp2->tm_mday = endDay;
    tmp2->tm_mon = endMonth;
    tmp2->tm_year = endYear;

    vector<Sensor *> * result = Clustering::findSimilarSensors(s,mktime(tmp1), mktime(tmp2));
/*
    cout << "liste des capteurs frauduleux :" << endl;
    for(int i=0; i< (*result).size(); i++){
        cout << (*result)[i] << endl;
    }
*/
    cout << endl << "Enter your choice :" << endl;
}
