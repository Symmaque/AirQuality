//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_PROVIDERINTERFACE_H
#define AIRQUALITY_PROVIDERINTERFACE_H

#include <string>
class ProviderInterface {
public:
    static void display();
    static bool authentication();
    static std::pair<std::string, std::string> getLogInInformations();
    static void chooseAction();
    static void displayMenu();
};


#endif //AIRQUALITY_PROVIDERINTERFACE_H
