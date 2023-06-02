#include "Donnees.h"

Donnees::Donnees(string cheminDossier)
{
    FluxImport flux;

    donneesCapteurs.listeCapteurs = flux.importerCapteurs(cheminDossier);
    /*donneesUtilisateurs.listeUtilisateurs = flux.importerUtilisateur();*/
    donneesPurificateurs.listePurificateurs = flux.importerPurificateurs();
}

Donnees::~Donnees()
{
}
