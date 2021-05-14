//
// Created by Aurélien on 04/05/2021.
//

#include "Provider.h"

vector<Cleaner*> * Provider::getListCleaners(){
    return listCleaners;
}

void Provider::addCleaner(Cleaner * cle)
{
    listCleaners->push_back(cle);
}

string Provider::toString()
{
    return "need to implement";
}

void Provider::setId(int id) {
    Provider::id = id;
}

ostream &operator<<(ostream &os, const Provider &provider) {
    os << "Id : " << provider.id << ", Password : " << provider.password << ", AdressListCleaners : " << provider.listCleaners << endl;
    return os;
}

Provider::Provider() {

}




