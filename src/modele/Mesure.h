#ifndef Mesure_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Mesure_H

// Inclusions des autres fichiers d'en-tête si nécessaire
using namespace std;
#include<string>


class Mesure {
    public : 
        float concentrationO3;
        float concentrationNO2;
        float concentrationSO2;
        float concentrationPM10;
        
        Mesure(float O3, float NO2, float SO2, float PM10) 
        : concentrationO3(O3), concentrationNO2(NO2), concentrationSO2(SO2), concentrationPM10(PM10){};


        
        virtual ~Mesure();   


    protected : 
    

};



#endif  // Fin des directives du préprocesseur