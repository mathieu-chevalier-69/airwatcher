#include <iostream>
#include "Donnees.h"

class Donnees{
    public:
        Donnees::Donnees()
        {
            FluxImport flux = new FluxImport();

            donneesCapteurs = new DonneesCapteurs();
            donneesCapteurs.setListeCapteurs(flux.importerCapteurs());

            donneesUtilisateurs = new DonneesUtilisateurs();
            donneesUtilisateurs.setListeUtilisateurs(flux.importerUtilisateur());

            donneesPurificateurs = new DonneesPurificateurs();
            donneesPurificateurs.setListePurificateurs(flux.importerPurificateur());
        }
        DonneesCapteurs Donnees::getDonneesCapteurs()
        {
            return donneesCapteurs;
        }
        DonneesUtilisateurs Donnees::getDonneesUtilisateurs()
        {
            return donneesUtilisateurs;
        }
        DonneesPurificateurs Donnees::getDonneesPurificateurs()
        {
            return donneesPurificateurs;
        }
        void Donnees::setDonneesCapteurs(DonneesCapteurs dc)
        {
            donneesCapteurs = dc;
        }
        void Donnees::setDonneesUtilisateurs(DonneesUtilisateurs du)
        {
            donneesUtilisateurs = du;
        }
        void Donnees::setDonneesPurificateurs(DonneesPurificateurs dp)
        {
            donneesPurificateurs = dp;
        }
        Donnees::~Donnees()
        {

        }
    
}