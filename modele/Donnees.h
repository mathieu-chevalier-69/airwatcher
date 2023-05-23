#include <iostream>
#include <DonneesCapteurs.h>
#include <DonneesUtilisateurs.h>
#include <DonneesPurificateurs.h>

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