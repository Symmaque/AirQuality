//
// Created by Aurélien on 04/05/2021.
//

#include "Measure.h"

#include <utility>

Measure::Measure()
{
    Measure::date = new Date;
}
Date *Measure::getDate() const
{
    return date;
}

void Measure::setDate(const Date *date)
{
    *Measure::date = *date;
}

int Measure::getSensorId() const
{
    return sensorId;
}

void Measure::setSensorId(int sensorId)
{
    Measure::sensorId = sensorId;
}

const Attribute &Measure::getAttribute() const
{
    return attribute;
}

void Measure::setAttribute(const Attribute &attribute)
{
    Measure::attribute = attribute;
}

double Measure::getValue() const
{
    return value;
}

void Measure::setValue(double value)
{
    Measure::value = value;
}

bool Measure::isReliable() const
{
    return reliable;
}

void Measure::setReliable(bool reliable)
{
    Measure::reliable = reliable;
}
/*
string Measure::toString()
{
    string str;
    str.append(asctime(localtime(date)));
    string bo;
    if (reliable)
    {
        bo = "Fiable";
    }
    else
    {
        bo = "Erronée";
    }
    return str + " " + std::to_string(sensorId) + " " + std::to_string(value) + " " + bo; //Attribute est nul : mettre toString()
}
*/
ostream& operator<<(ostream& os, const Measure& measure) {
    os << "[ Date : " << *measure.date << ", Reliable : " << measure.reliable << ", Sensor : " << measure.sensorId << ", Value :  "<< measure.value << ", Unit : " << measure.attribute << " ]";
    return os;
}

Date::Date(const string& date) {
    Date::year = date.substr(0,4);
    Date::month = date.substr(5,2);
    Date::day = date.substr(8,2);
}

Date::Date(string year, string month, string day) {
    Date::year = std::move(year);
    Date::month = std::move(month);
    Date::day = std::move(day);
}

ostream &operator<<(ostream &os, const Date &date) {
    os << date.year << " " << date.month << " " << date.day;
    return os;
}

Date::Date() {
    year = "YYYY";
    month = "MM";
    day = "DD";
}
