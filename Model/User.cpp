//
// Created by Aurélien on 04/05/2021.
//

#include "User.h"


int User::getId() {
    return id;
}

std::string User::getPassword() {
    return password;
}

void User::setPassword(std::string string) {
    password = string;
}
