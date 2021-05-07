//
// Created by Aurélien on 04/05/2021.
//

#include "Stats.h"

double Stats::ATMOPeriodMean(const time_t &startDate, const time_t &endDate, double longitude, double latitude) {
    return latitude;
}

double Stats::ATMOInstantMean(const time_t &date, double longitude, double latitude) {
    //Call ATMO instant mean with matching sensor
    return 0;
}

double Stats::ATMOSensorLifespanMean(const Sensor & sensor) {
    int indiceSum = 0;
    auto measures = sensor.getMeasures();

    for (auto it = measures.begin() ; it != measures.end(); it += 4) {
        Measure O3Measure = it[0];
        Measure NO2Measure = it[1];
        Measure SO2Measure = it[2];
        Measure PM10Measure = it[3];
        int o3 = ATMOGaz(O3Measure.getAttribute().getId(), O3Measure.getValue());
        int no2 = ATMOGaz(NO2Measure.getAttribute().getId(), O3Measure.getValue());
        int so2 = ATMOGaz(SO2Measure.getAttribute().getId(), O3Measure.getValue());
        int pm10 = ATMOGaz(PM10Measure.getAttribute().getId(), O3Measure.getValue());
        int maxIndice = max(max(max(o3, no2), so2), pm10);
        indiceSum += maxIndice;
    }
    //And return the mean
    return indiceSum / (double) measures.size() / 4.0;
}
double Stats::ATMOInstantMean(Date date, const Sensor & sensor) {

}

int Stats::ATMOGaz(const string& attributeId, double value) {
    if (attributeId == "O2") {
        if(value >= 0 && value <= 29) return 1;
        if(value >= 30 && value <= 54) return 2;
        if(value >= 55 && value <= 79) return 3;
        if(value >= 80 && value <= 104) return 4;
        if(value >= 105 && value <= 129) return 5;
        if(value >= 130 && value <= 149) return 6;
        if(value >= 150 && value <= 179) return 7;
        if(value >= 180 && value <= 209) return 8;
        if(value >= 210 && value <= 239) return 9;
        if(value >= 240) return 10;
    } else if(attributeId == "SO2") {
        if(value >= 0 && value < 39) return 1;
        if(value >= 40 && value < 79) return 2;
        if(value >= 80 && value < 119) return 3;
        if(value >= 120 && value < 159) return 4;
        if(value >= 160 && value < 199) return 5;
        if(value >= 200 && value < 249) return 6;
        if(value >= 250 && value < 299) return 7;
        if(value >= 250 && value < 299) return 8;
        if(value >= 300 && value < 399) return 9;
        if(value >= 400 && value < 499) return 10;
    } else if(attributeId == "NO2") {
        if(value >= 0 && value < 29) return 1;
        if(value >= 30 && value < 54) return 2;
        if(value >= 55 && value < 84) return 3;
        if(value >= 85 && value < 109) return 4;
        if(value >= 110 && value < 134) return 5;
        if(value >= 135 && value < 164) return 6;
        if(value >= 165 && value < 199) return 7;
        if(value >= 200 && value < 274) return 8;
        if(value >= 275 && value < 399) return 9;
        if(value >= 400) return 10;
    } else if(attributeId == "PM10") {
        if(value >= 0 && value < 6) return 1;
        if(value >= 7 && value < 13) return 2;
        if(value >= 14 && value < 20) return 3;
        if(value >= 21 && value < 27) return 4;
        if(value >= 28 && value < 34) return 5;
        if(value >= 35 && value < 41) return 6;
        if(value >= 42 && value < 49) return 7;
        if(value >= 50 && value < 64) return 8;
        if(value >= 65 && value < 79) return 9;
        if(value >= 80) return 10;
    }
}

