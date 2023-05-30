#ifndef Mesure_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Mesure_H

// Inclusions des autres fichiers d'en-tête si nécessaire
using namespace std;
#include<string>
#include <iostream>

class Mesure {
    public : 
        //Attributs Mesure
        float concentrationO3;
        float concentrationNO2;
        float concentrationSO2;
        float concentrationPM10;

        //Constructeur et Déstructeur
        Mesure()
        : concentrationO3(0), concentrationNO2(0), concentrationSO2(0), concentrationPM10(0){};
        Mesure(const float O3, const float NO2, const float SO2, const float PM10) 
        : concentrationO3(O3), concentrationNO2(NO2), concentrationSO2(SO2), concentrationPM10(PM10){};

        virtual ~Mesure();   


        void setAttribute(string, float);
        friend ostream& operator<<(ostream& os, const Mesure& dt);
        Mesure & operator+=(const Mesure & other);

    

};



#endif  // Fin des directives du préprocesseur