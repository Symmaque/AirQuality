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
    cout << " Sensor id = " << sensor.getSensorId() << endl;
    int indiceSum = 0;
    auto measures = sensor.getMeasures();

    for (auto it = measures->begin() ; it != measures->end(); it += 4) {
        //cout << "Measure = " << (*it)->getValue() << endl;
        Measure O3Measure = *it[0];
        Measure NO2Measure = *it[1];
        Measure SO2Measure = *it[2];
        Measure PM10Measure = *it[3];
        int o3 = ATMOGaz(O3Measure.getAttribute().getId(), O3Measure.getValue());
        int no2 = ATMOGaz(NO2Measure.getAttribute().getId(), NO2Measure.getValue());
        int so2 = ATMOGaz(SO2Measure.getAttribute().getId(), SO2Measure.getValue());
        int pm10 = ATMOGaz(PM10Measure.getAttribute().getId(), PM10Measure.getValue());
        //cout << " O3 = " << o3 << " NO2 = " << no2 << " SO2 " << so2 << " PM10 " << pm10 << endl;
        int maxIndice = max(max(max(o3, no2), so2), pm10);
        indiceSum += maxIndice;
    }
    cout << "Returned mean = " << indiceSum / ((double) measures->size() / 4.0) << endl;
    //And return the mean
    return indiceSum / ((double) measures->size() / 4.0);
}
double Stats::ATMOInstantMean(time_t date, const Sensor & sensor) {
    return 0.0;
}

int Stats::ATMOGaz(const string& attributeId, double value) {
    //cout << "Attribute asked : " << attributeId << " value = " << value << endl;
    if (attributeId == "O3") {
        if(value >= 0 && value <= 29) return 1;
        if(value >= 29 && value <= 54) return 2;
        if(value >= 54 && value <= 79) return 3;
        if(value >= 79 && value <= 104) return 4;
        if(value >= 104 && value <= 129) return 5;
        if(value >= 129 && value <= 149) return 6;
        if(value >= 149 && value <= 179) return 7;
        if(value >= 179 && value <= 209) return 8;
        if(value >= 209 && value <= 239) return 9;
        if(value >= 239) return 10;
    } else if(attributeId == "SO2") {
        if(value >= 0 && value < 39) return 1;
        if(value >= 39 && value < 79) return 2;
        if(value >= 79 && value < 119) return 3;
        if(value >= 119 && value < 159) return 4;
        if(value >= 159 && value < 199) return 5;
        if(value >= 199 && value < 249) return 6;
        if(value >= 249 && value < 299) return 7;
        if(value >= 299 && value < 399) return 8;
        if(value >= 399 && value < 499) return 9;
        if(value >= 499) return 10;
    } else if(attributeId == "NO2") {
        if(value >= 0 && value < 29) return 1;
        if(value >= 29 && value < 54) return 2;
        if(value >= 54 && value < 84) return 3;
        if(value >= 84 && value < 109) return 4;
        if(value >= 109 && value < 134) return 5;
        if(value >= 134 && value < 164) return 6;
        if(value >= 164 && value < 199) return 7;
        if(value >= 199 && value < 274) return 8;
        if(value >= 274 && value < 399) return 9;
        if(value >= 399) return 10;
    } else if(attributeId == "PM10") {
        if(value >= 0 && value < 6) return 1;
        if(value >= 6 && value < 13) return 2;
        if(value >= 13 && value < 20) return 3;
        if(value >= 20 && value < 27) return 4;
        if(value >= 27 && value < 34) return 5;
        if(value >= 34 && value < 41) return 6;
        if(value >= 41 && value < 49) return 7;
        if(value >= 49 && value < 64) return 8;
        if(value >= 64 && value < 79) return 9;
        if(value >= 79) return 10;
    }
}

