#include <iostream>
#include <ctime>
#include "services/Clustering.h"
#include "interface/IndividualInterface.h"
#include "interface/ProviderInterface.h"
#include "interface/GovernmentInterface.h"

#include "data/DataAccess.h"
#include "data/Reader.h"
using namespace std;

enum userType {INDIVIDUAL = 1, PROVIDER, GOVERNMENT, ADMIN};

bool menu(int& choice){

    switch(choice){
        case INDIVIDUAL:
            if(IndividualInterface::authentication())
                IndividualInterface::display();
            else{
                cout << "Authentication impossible" << endl;
                return false;
            }
            break;
        case PROVIDER:
            if(ProviderInterface::authentication())
                ProviderInterface::display();
            else{
                cout << "Authentication impossible" << endl;
                return false;
            }
            break;
        case GOVERNMENT:
            if(GovernmentInterface::authentication())
                GovernmentInterface::display();
            else{
                cout << "Authentication impossible" << endl;
                return false;
            }
            break;
        case ADMIN:
            cout << "Admin connection" << endl;
            break;
        default:
            cout << "Enter a valid number please : " << endl;
            cin >> choice;
            return false;
    }
    return true;
}

void userTypeChoice(){
    int choice = 0;
    cin >> choice;  //TODO : safe input
    while(!menu(choice)){}
}

void displayFirstInterface(){
    cout << "--------------- BIENVENUE SUR L'APPLICATION AIR DE QUALITE ---------------" << endl << endl;
    cout << "Veuillez choisir le type d’utilisateur afin de vous authentifier ou de vous inscrire : " << endl;
    cout << "1-Utilisateur normal" << endl;
    cout << "2-Fournisseur" << endl;
    cout << "3-Gouvernement" << endl;
    cout << "4-Admin" << endl;

    userTypeChoice();
}

int main() {
    DataAccess::init("../../resources/release/");
    displayFirstInterface();
    return 0;
}
