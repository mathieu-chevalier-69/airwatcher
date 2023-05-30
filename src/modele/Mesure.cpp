#include <iostream>
#include "Mesure.h"

Mesure::~Mesure() {}

void Mesure::setAttribute(string id, float value)
{
    if (id == "O3")
    {
        concentrationO3 = value;
    }
    else if (id == "SO2")
    {
        concentrationSO2 = value;
    }
    else if (id == "NO2")
    {
        concentrationNO2 = value;
    }
    else if ("PM10")
    {
        concentrationPM10 = value;
    }
}

ostream &operator<<(ostream &os, const Mesure &ms)
{
    os << "O3: " << ms.concentrationO3 << " / NO2: " << ms.concentrationNO2 << " / SO2: " << ms.concentrationSO2 << " / PM10: " << ms.concentrationPM10;
    return os;
}

Mesure &Mesure::operator+=(const Mesure &other)
{
    concentrationO3 += other.concentrationO3;
    concentrationNO2 += other.concentrationNO2;
    concentrationSO2 += other.concentrationSO2;
    concentrationPM10 += other.concentrationPM10;
    return *this;
}

Mesure &Mesure::operator/(const int &diviseur)
{
    concentrationO3 /= diviseur;
    concentrationNO2 /= diviseur;
    concentrationSO2 /= diviseur;
    concentrationPM10 /= diviseur;
    return *this;
}