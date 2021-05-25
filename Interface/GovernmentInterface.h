//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_GOVERNMENTINTERFACE_H
#define AIRQUALITY_GOVERNMENTINTERFACE_H

#include <string>
class GovernmentInterface {
public:
    static void display();
    static bool authentication();
    static std::pair<std::string, std::string> getLogInInformations();
    static void chooseAction();
    static void displayMenu();

    static void displayDetectFraud();
};


#endif //AIRQUALITY_GOVERNMENTINTERFACE_H
