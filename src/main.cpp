#include <iostream>
#include "services/Clustering.h"
#include "interface/IndividualInterface.h"
#include "interface/ProviderInterface.h"
#include "interface/GovernmentInterface.h"
#include "interface/InterfaceUtils.h"
#include "data/DataAccess.h"


using namespace std;

enum userType {
    INDIVIDUAL = 1, PROVIDER, GOVERNMENT
};

bool menu(int &choice) {

    switch (choice) {
        case INDIVIDUAL:
            if (IndividualInterface::authentication()) {
                IndividualInterface::display();
            } else {
                cout << "Authentification impossible" << endl;
                return false;
            }
            break;
        case PROVIDER:
            if (ProviderInterface::authentication()) {
                ProviderInterface::display();
            } else {
                cout << "Authentification impossible" << endl;
                return false;
            }
            break;
        case GOVERNMENT:
            if (GovernmentInterface::authenticate()) {
                GovernmentInterface::display();
            } else {
                cout << "Authentification impossible" << endl;
                return false;
            }
            break;
        default:
            cout << "Enter a valid number please : " << endl;
            choice = InterfaceUtils::inputNumber();
            return false;
    }
    return true;
}

void userTypeChoice() {
    int choice = 0;
    cin >> choice;
    while (!menu(choice)) {}
}

void displayFirstInterface() {
    cout << "--------------- BIENVENUE SUR L'APPLICATION AIR DE QUALITE ---------------" << endl << endl;
    cout << "Veuillez choisir le type d’utilisateur afin de vous authentifier ou de vous inscrire : " << endl;
    cout << "1-Utilisateur normal" << endl;
    cout << "2-Fournisseur" << endl;
    cout << "3-Gouvernement" << endl;

    userTypeChoice();
}

int main() {
    DataAccess::init("../../resources/release/");
    displayFirstInterface();
    return 0;
}