//
// Created by Aurélien on 04/05/2021.
//

#include "Provider.h"

vector<Cleaner> * Provider::getListCleaners() const {
    return listCleaners;
}

void Provider::addCleaner(Cleaner cle)
{
    listCleaners->push_back(cle);
}

string Provider::toString()
{
    return "need to implement";
}

