#ifndef Donnees_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Donnees_H

#include <iostream>
#include <string>
using namespace std;

#include "DonneesCapteurs.h"
#include "DonneesUtilisateurs.h"
#include "DonneesPurificateurs.h"

class Donnees{
    public:

        //Attributs
        DonneesCapteurs donneesCapteurs;
        DonneesUtilisateurs donneesUtilisateurs;
        DonneesPurificateurs donneesPurificateurs;
        
        //Constructeur - Destructeur
        Donnees();
        ~Donnees();
};

#endif