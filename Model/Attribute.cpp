//
// Created by Aurélien on 04/05/2021.
//

#include "Attribute.h"

Attribute::Attribute() {}

const string &Attribute::getUnit() const
{
    return unit;
}

void Attribute::setUnit(const string &unit)
{
    Attribute::unit = unit;
}

const string &Attribute::getDescription() const
{
    return description;
}

void Attribute::setDescription(const string &description)
{
    Attribute::description = description;
}

Attribute::~Attribute()
{
}

string Attribute::toString()
{
    return Attribute::unit + ", " + Attribute::description;
}

ostream &operator<<(ostream& os, const Attribute& attribute) {
    os << attribute.unit << " " << attribute.description;
    return os;
}
