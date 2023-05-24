#include <iostream>
#include "FluxImport.h"
using namespace std;

#include "Donnees.h"


        Donnees::Donnees()
        :donneesCapteurs(DonneesCapteurs())
        {
            FluxImport flux;
            
            donneesCapteurs.listeCapteurs = flux.importerCapteurs();
            /*donneesUtilisateurs.listeUtilisateurs = flux.importerUtilisateur();
            donneesPurificateurs.listePurificateurs = flux.importerPurificateur();*/
        }
        
        Donnees::~Donnees()
        {

        }
    
