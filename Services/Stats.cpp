//
// Created by Aurélien on 04/05/2021.
//

#include "Stats.h"

double Stats::ATMOPeriodMean(const time_t &startDate, const time_t &endDate, double longitude, double latitude) {
    return latitude;
}

double Stats::ATMOInstantMean(const time_t &date, double longitude, double latitude) {
    return 0;
}

double Stats::ATMOInstantMean(const Sensor & sensor) {
    return 0;
}