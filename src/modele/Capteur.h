#ifndef Capteur_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Capteur_H

// Inclusions des autres fichiers d'en-tête si nécessaire
using namespace std;
#include<string>
#include<map>

#include"../utile/Coordonee.h"
#include"../utile/Date.h"
#include "Mesure.h"

class Capteur {
    public : 
        string id; 
        Coordonee coordonee;
        map<Date, Mesure> mesures;
        string proprietaire;
        Capteur(string id, float longitude, float latitude, string proprietaire) : id(id), proprietaire(proprietaire){};


        
        virtual ~Capteur();   


    protected : 
    

};



#endif  // Fin des directives du préprocesseur