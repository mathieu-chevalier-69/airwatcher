#include <iostream>
#include "Donnees.h"

class Donnees{
    public:
        Donnees();
        DonneesCapteurs getDonneesCapteurs();
        DonneesUtilisateurs getDonneesUtilisateurs();
        DonneesPurificateurs getDonneesPurificateurs();
        ~Donnees();
    private:
        DonneesCapteurs donneesCapteurs;
        DonneesUtilisateurs donneesUtilisateurs;
        DonneesPurificateurs donneesPurificateurs;
}