#include "Donnees.h"
#include <time.h>
#include<string>

Donnees::Donnees(string cheminDossier)
{
    FluxImport flux;
    clock_t t = clock();
    donneesCapteurs.listeCapteurs = flux.importerCapteurs(cheminDossier);
    clock_t apresCapteurs = clock();
    /*donneesUtilisateurs.listeUtilisateurs = flux.importerUtilisateur();*/
    donneesPurificateurs.listePurificateurs = flux.importerPurificateurs(cheminDossier);
    clock_t apresPurificateurs = clock();
    donneesCapteurs.listeCapteurs = FluxImport::retirerCapteursErrones(donneesCapteurs.listeCapteurs, 20.0f);
    clock_t apresCapteursErrones = clock();
    cout << "Importation des capteurs en " << ((double) (apresCapteurs - t)) / CLOCKS_PER_SEC << "ms"<< endl;
    cout << "Importation des purificateurs en " << ((double) (apresPurificateurs - apresCapteurs)) / CLOCKS_PER_SEC << "ms"<< endl;
    cout << "Retrait des capteurs erronés en " << ((double) (apresCapteursErrones - apresPurificateurs)) / CLOCKS_PER_SEC << "ms"<< endl;

}
Donnees::~Donnees()
{
}
