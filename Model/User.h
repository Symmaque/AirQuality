//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_USER_H
#define AIRQUALITY_USER_H


#include <string>

class User {
protected:
    int id;
    std::string password;

public:

    int getId();
    std::string getPassword();
    void setPassword(std::string string);
};


#endif //AIRQUALITY_USER_H
