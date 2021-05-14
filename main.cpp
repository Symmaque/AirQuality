#include <iostream>
#include <ctime>
#include "Services/Clustering.h"
#include "Interface/IndividualInterface.h"
#include "Interface/ProviderInterface.h"
#include "Interface/GovernmentInterface.h"

#include "Data/DataAccess.h"
#include "Data/Reader.h"
using namespace std;


void testfindSimilarSensors(){
    auto sensor1 = Sensor(1,2.0,2.0);
    time_t start = time(nullptr);
    time_t end = time(nullptr);
    cout << "Start : " << start << endl;
    cout << "End : " << end<< endl;
    auto * similarSensors = Clustering::findSimilarSensors(sensor1,start,end);
    if(similarSensors == nullptr){
        cerr << "similarSensor is nullptr " << endl;
        return;
    }

    for(auto & sensor : *similarSensors){
        cout << *sensor << endl;
    }

    delete similarSensors;
}

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
    //displayFirstInterface();

    //testfindSimilarSensors();


    /*
    for(const auto& individual: individuals){
        cout << individual << endl;
    }*/
    /*
    for(const auto& sensor: sensors){
        cout << sensor << endl;
    }*/

    DataAccess::init();
/*
    for(const auto& measure: *DataAccess::getListMeasures()){
        cout << measure << endl;
    }
  */
/*
    for(const auto& attribute : *DataAccess::getListAttribute()){
        cout << attribute << endl;
    }
  */
/*
    for(const auto& sensor : sensors){
        cout << sensor << endl;
    }*/
    /*
    for(const auto& individual : *DataAccess::getListIndividuals()){
        cout << individual << endl;
    }*/

    for(const auto& cleaner : *DataAccess::getListCleaners()){
        cout << cleaner << endl;
    }



    return 0;
}
