//
// Created by Aurélien on 04/05/2021.
//

#include "User.h"

int User::getId()
{
    return id;
}

string User::getPassword()
{
    return password;
}

void User::setPassword(string string)
{
    password = string;
}

User::User(int id, string password)
{
    User::id = move(id);
    User::password = move(password);
}

User::User()
{
}

string User::toString()
{
    return User::id + " " + User::password;
}

ostream &operator<<(ostream &os, const User &user) {
    os << "Id : " << user.id << endl << "Password : " << user.password << endl;
    return os;
}
