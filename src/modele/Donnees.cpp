#include <iostream>
#include "Donnees.h"

class Donnees{
    public:
        Donnees()
        {
            FluxImport flux = new FluxImport();

            donneesCapteurs = new DonneesCapteurs();
            donneesCapteurs.setListeCapteurs(flux.importerCapteurs());

            donneesUtilisateurs = new DonneesUtilisateurs();
            donneesUtilisateurs.setListeUtilisateurs(flux.importerUtilisateur());

            donneesPurificateurs = new DonneesPurificateurs();
            donneesPurificateurs.setListePurificateurs(flux.importerPurificateur());
        }
        DonneesCapteurs getDonneesCapteurs()
        {
            return donneesCapteurs;
        }
        DonneesUtilisateurs getDonneesUtilisateurs()
        {
            return donneesUtilisateurs;
        }
        DonneesPurificateurs getDonneesPurificateurs()
        {
            return donneesPurificateurs;
        }
        void setDonneesCapteurs(DonneesCapteurs dc)
        {
            donneesCapteurs = dc;
        }
        void setDonneesUtilisateurs(DonneesUtilisateurs du)
        {
            donneesUtilisateurs = du;
        }
        void setDonneesPurificateurs(DonneesPurificateurs dp)
        {
            donneesPurificateurs = dp;
        }
        ~Donnees()
        {

        }
    
}