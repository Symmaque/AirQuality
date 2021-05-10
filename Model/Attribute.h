//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_ATTRIBUTE_H
#define AIRQUALITY_ATTRIBUTE_H

#include <string>
#include <iostream>
using namespace std;
class Attribute
{
public:
    Attribute();
    string getUnit() const;
    void setUnit(const string &unit);
    const string &getDescription() const;
    void setDescription(const string &description);
    string toString();

    friend ostream& operator<<(ostream& os, const Attribute& attribute);

    const string &getId() const;

    void setId(const string &id);

private:
    string id;
    string unit;
    string description;

public:
    virtual ~Attribute();
};

#endif //AIRQUALITY_ATTRIBUTE_H