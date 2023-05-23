#ifndef Capteur_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Capteur_H

// Inclusions des autres fichiers d'en-tête si nécessaire
using namespace std;
#include<string>
#include<map>
#include<utility>

#include"../utile/Coordonnees.h"
#include"../utile/Date.h"
#include "Mesure.h"

typedef map<Date,Mesure> MapMesures;
class Capteur {
    public : 

        string id; 
        Coordonnees coordonees;
        MapMesures mesures;
        string proprietaire;

        Capteur(const string & id, const float & longitude, const float & latitude, const string & proprietaire)
        : id(id), coordonees(latitude, longitude), proprietaire(proprietaire){};

        void ajouterMesure(const Mesure & mesure, const Date & date);
        
        virtual ~Capteur();   


    protected : 
    

};



#endif  // Fin des directives du préprocesseur