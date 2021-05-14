//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_CLEANER_H
#define AIRQUALITY_CLEANER_H

#include <ctime>
#include <iostream>

using namespace std;
class Cleaner {
public:
    int getId() const;

    void setId(int id);

    double getLatitude() const;

    void setLatitude(double latitude);

    double getLongitude() const;

    void setLongitude(double longitude);

    time_t getStartDate() const;

    void setStartDate(time_t startDate);

    time_t getEndDate() const;

    void setEndDate(time_t endDate);

    friend ostream& operator<<(ostream& os, const Cleaner& cleaner);


protected:
    int id;
    double latitude;
    double longitude;
    time_t startDate;
    time_t endDate;
};




#endif //AIRQUALITY_CLEANER_H
