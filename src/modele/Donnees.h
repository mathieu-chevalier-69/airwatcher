#include <iostream>
#include <string>
using namespace std;

#include "DonneesCapteurs.h"
#include "DonneesUtilisateurs.h"
#include "DonneesPurificateurs.h"
#include "FluxImport.h"

class Donnees{
    public:
        Donnees();
        ~Donnees();
        DonneesCapteurs donneesCapteurs;
        DonneesUtilisateurs donneesUtilisateurs;
        DonneesPurificateurs donneesPurificateurs;
};