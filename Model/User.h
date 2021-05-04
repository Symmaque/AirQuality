//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_USER_H
#define AIRQUALITY_USER_H

#include <string>

using namespace std;

class User
{

protected:
    int id{};
    string password;

public:
    int getId();
    std::string getPassword();
    void setPassword(string string);

    User();
    User(int id, string password);
    string toString();
};

#endif //AIRQUALITY_USER_H
