#include <iostream>
#include "DonneesCapteurs.h"
#include "DonneesUtilisateurs.h"
#include "DonneesPurificateurs.h"

class Donnees{
    public:
        Donnees();
        DonneesCapteurs getDonneesCapteurs();
        DonneesUtilisateurs getDonneesUtilisateurs();
        DonneesPurificateurs getDonneesPurificateurs();
        void setDonneesCapteurs(DonneesCapteurs);
        void setDonneesUtilisateurs(DonneesUtilisateurs);
        void setDonneesPurificateurs(DonneesPurificateurs);
        ~Donnees();
    private:
        DonneesCapteurs donneesCapteurs;
        DonneesUtilisateurs donneesUtilisateurs;
        DonneesPurificateurs donneesPurificateurs;
}