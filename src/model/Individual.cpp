//
// Created by Aurélien on 04/05/2021.
//

#include "Individual.h"

bool Individual::getMalicious() const
{
    return malicious;
}

void Individual::setMalicious(bool malicious)
{
    Individual::malicious = malicious;
}

int Individual::getPoints() const
{
    return points;
}

void Individual::setPoints(int points)
{
    Individual::points = points;
}

Sensor *Individual::getSensor() const
{
    return sensor;
}

void Individual::setSensor(Sensor * sensor)
{
    Individual::sensor = sensor;
}

string Individual::toString()
{
    return "individual toString";
}

int Individual::getId() const
{
    return id;
}

void Individual::setId(const int id)
{
    Individual::id = id;
}

Individual::Individual() {}

ostream &operator<<(ostream &os, const Individual &individual) {
    os << "Id : " << individual.id << endl << "Password : " << individual.password << endl << "SensorId : " << individual.sensor->getSensorId() << endl;
    return os;
}

bool operator==(const Individual &first, const Individual &second) {
    return first.getId() == second.getId();
}