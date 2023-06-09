#include "Donnees.h"
#include <time.h>
#include<string>

Donnees::Donnees(string cheminDossier)
{
    FluxImport flux;
    cout << "Importation des données en cours" << endl;
    clock_t avantCapteurs = clock();
    donneesCapteurs.listeCapteurs = flux.importerCapteurs(cheminDossier);
    clock_t apresCapteurs = clock();
    /*donneesUtilisateurs.listeUtilisateurs = flux.importerUtilisateur();*/
    donneesPurificateurs.listePurificateurs = flux.importerPurificateurs(cheminDossier);
    clock_t apresPurificateurs = clock();
    FluxImport::retirerCapteursErrones(donneesCapteurs.listeCapteurs, 40.0f);
    clock_t apresCapteursErrones = clock();
    cout << "Importation des capteurs en " << ((double) (apresCapteurs - avantCapteurs)) / CLOCKS_PER_SEC << "s"<< endl;
    cout << "Importation des purificateurs en " << ((double) (apresPurificateurs - apresCapteurs)) / CLOCKS_PER_SEC << "s"<< endl;
    cout << "Retrait des capteurs erronés en " << ((double) (apresCapteursErrones - apresPurificateurs)) / CLOCKS_PER_SEC << "s"<< endl;

}
Donnees::~Donnees()
{
}
