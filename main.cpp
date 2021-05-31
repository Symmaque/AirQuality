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
    auto * sensors = DataAccess::getListSensors();

    auto sensor1 = (*sensors)[0];

    tm *tmp = new tm();
    tmp->tm_mday = 16;
    tmp->tm_mon = 7 - 1;
    tmp->tm_year = 2019 - 1900;
    time_t start = mktime(tmp);

    tmp->tm_mday = 16;
    tmp->tm_mon = 10 - 1;
    tmp->tm_year = 2019 - 1900;
    time_t end = mktime(tmp);

    cout << "Start : " << start << endl;
    cout << "End : " << end << endl;
    auto * similarSensors = Clustering::findSimilarSensors(sensor1,start,end);
    if(similarSensors == nullptr){
        cerr << "similarSensor is nullptr " << endl;
        return;
    }

    cout << "Dix premiers capteurs similaires : ################################################" << endl << endl;
    for(int i = 0; i < 10 && i < similarSensors->size(); i++){
        cout << *(*similarSensors)[i] << endl;
    }

    delete similarSensors;
}
enum userType {INDIVIDUAL = 1, PROVIDER, GOVERNMENT};

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

    userTypeChoice();
}

int main() {
    

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
    //testfindSimilarSensors();
    displayFirstInterface();
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
