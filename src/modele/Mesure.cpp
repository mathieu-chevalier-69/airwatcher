#include "Mesure.h"

Mesure::~Mesure(){}

void Mesure::setAttribute(string id, float value)
{
    if (id == "O3"){
        concentrationO3 = value;
    }else if(id == "SO2"){
        concentrationSO2 = value;
    }else if(id == "NO2"){
        concentrationNO2 = value;
    }else if("PM10"){
        concentrationPM10 = value;
    }
}