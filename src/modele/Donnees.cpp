#include <iostream>
using namespace std;

#include "Donnees.h"


        Donnees::Donnees()
        {
            FluxImport flux = new FluxImport();

            donneesCapteurs = new DonneesCapteurs();
            donneesCapteurs.listeCapteurs = flux.importerCapteurs();

            donneesUtilisateurs = new DonneesUtilisateurs();
            donneesUtilisateurs.listeUtilisateurs = flux.importerUtilisateur();

            donneesPurificateurs = new DonneesPurificateurs();
            donneesPurificateurs.listePurificateurs = flux.importerPurificateur();
        }
        
        Donnees::~Donnees()
        {

        }
    
