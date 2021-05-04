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
    int id;
    vector<Cleaner> * listCleaners;

public:
    vector<Cleaner> * getListCleaners() const;
    string toString();
    void addCleaner(Cleaner cle);
    Provider();
};


#endif //AIRQUALITY_PROVIDER_H
