//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_ATTRIBUTE_H
#define AIRQUALITY_ATTRIBUTE_H

#include <string>

using namespace std;
class Attribute {
public:
    const string &getUnit() const;
    void setUnit(const string &unit);
    const string &getDescription() const;
    void setDescription(const string &description);

private:
    string unit;
public:
    virtual ~Attribute();

private:
    string description;
};

#endif //AIRQUALITY_ATTRIBUTE_H