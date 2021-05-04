//
// Created by Aurélien on 04/05/2021.
//

#include "User.h"


int User::getId() {
    return id;
}

string User::getPassword() {
    return password;
}

void User::setPassword(string string) {
    password = string;
}

User::User(int id, string password) {
    this->id = move(id);
    this->password = move(password);
}

User::User() {

}
