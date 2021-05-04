//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_PROVIDER_H
#define AIRQUALITY_PROVIDER_H


#include "User.h"
#include "Cleaner.h"
#include <vector>

using namespace std;
class Provider : public User{
protected:
    vector<Cleaner> listCleaners;
public:
    const vector<Cleaner> &getListCleaners() const;
    string toString();

};


#endif //AIRQUALITY_PROVIDER_H
