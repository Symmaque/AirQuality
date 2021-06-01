//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_INDIVIDUALINTERFACE_H
#define AIRQUALITY_INDIVIDUALINTERFACE_H

#include <string>
class IndividualInterface {
public:
    static void display();
    static bool authentication();
    static std::pair<int, std::string> getLogInInformations();
    static void chooseAction();
    static void displayMenu();
    static void displaySimilarSensors();
};


#endif //AIRQUALITY_INDIVIDUALINTERFACE_H
