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
    const string &getUnit() const;
    void setUnit(const string &unit);
    const string &getDescription() const;
    void setDescription(const string &description);
    string toString();

    friend ostream& operator<<(ostream& os, const Attribute& attribute);

private:
    string unit;

public:
    virtual ~Attribute();

private:
    string description;
};

#endif //AIRQUALITY_ATTRIBUTE_H