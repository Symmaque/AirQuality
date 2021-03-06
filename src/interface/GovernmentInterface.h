//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_GOVERNMENTINTERFACE_H
#define AIRQUALITY_GOVERNMENTINTERFACE_H

#include <string>
class GovernmentInterface {
public:
    static void display();
    static bool authenticate();
    static std::pair<int, std::string> getLogInInformations();
    static void chooseAction();
    static void displayMenu();

    static void displayDetectUserFraud();
    static void displayDetectAnyFraud();
    static void displayRemoveFrauds();
};


#endif //AIRQUALITY_GOVERNMENTINTERFACE_H
