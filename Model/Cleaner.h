//
// Created by Aurélien on 04/05/2021.
//

#ifndef AIRQUALITY_CLEANER_H
#define AIRQUALITY_CLEANER_H

#include <ctime>
#include "Provider.h"

class Cleaner {
public:
    int getId() const;

    void setId(int id);

    double getLatitude() const;

    void setLatitude(double latitude);

    double getLongitude() const;

    void setLongitude(double longitude);

    tm *getStartDate() const;

    void setStartDate(tm *startDate);

    tm *getEndDate() const;

    void setEndDate(tm *endDate);

    const Provider &getProvider() const;

    void setProvider(const Provider &provider);

protected:
    int id;
    double latitude;
    double longitude;
    tm * startDate;
    tm * endDate;
    Provider provider;
};




#endif //AIRQUALITY_CLEANER_H
