#include "Mesure.h"

Mesure::~Mesure(){}

void Mesure::setAttribute(string id, float value)
{
    switch(id)
    {
        case "O3":
            concentrationO3 = value;
            break;
        case "SO2":
            concentrationSO2 = value;
            break;
        case "NO2":
            concentrationNO2 = value;
            break;
        case "PM10":
            concentrationPM10 = value;
            break;
        default:
            cout << "Erreur lors de la modification de l'attribut\n";
            break;
    }
}