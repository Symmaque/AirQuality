//
// Created by Aurélien on 04/05/2021.
//

#include "Measure.h"


Measure::Measure()
{
    Measure::date = new time_t;
    Measure::attribute = new Attribute;
}
time_t *Measure::getDate() const
{
    return date;
}

void Measure::setDate(time_t date)
{
    *Measure::date = date;
}

int Measure::getSensorId() const
{
    return sensorId;
}

void Measure::setSensorId(int sensorId){
    Measure::sensorId = sensorId;
}

const Attribute &Measure::getAttribute() const{
    return *attribute;
}

void Measure::setAttribute(Attribute *attribute){
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
    auto * tmp = localtime(measure.date);
    os << "[ Date : " << tmp->tm_year + 1900 << "-" << tmp->tm_mon + 1 << "-" << tmp->tm_mday << ", Reliable : " << measure.reliable << ", Sensor : " << measure.sensorId << ", Value :  "<< measure.value << ", Unit : " << *measure.attribute << " ]";
    return os;
}

Measure::~Measure() {
    //delete Measure::attribute;
    //delete Measure::date;
}


