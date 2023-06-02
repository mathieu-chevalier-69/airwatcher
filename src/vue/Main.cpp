#include "../utile/Date.h"
#include "../modele/Capteur.h"
#include "../modele/Mesure.h"
#include "../modele/Donnees.h"
#include "../controle/Service.h"
#include "../test/Test.h"
#include "../utile/Saisie.h"
#include <iostream>
#include <string>


int main()
{
    Service service; 
    int choix = 0;
    do{
        cout << "0. Quitter" << endl;
        cout << "1. Exécuter tous les tests" << endl;
        cout << "2. Calculer qualité de l'air sur une zone donnée" << endl;
        cout << "3. Consulter l'impact d'un purificateur" << endl;
        choix = Saisie::saisirInt("Choisissez une option");
        Coordonnees coordonnees;
        Date dateDebut, dateFin;
        int rayon;
        string idPurificateur;
        pair<Mesure, Mesure> mesures;
        switch(choix)
        {
            case 1:
                cout << "Exécution des tests" << endl;
                break;
            case 2:
                coordonnees = Saisie::saisirCoordonnees("Saisissez les coordonnées du point central");
                rayon = Saisie::saisirInt("Saisissez le rayon (km)");
                dateDebut = Saisie::saisirDate("Saisissez la date de début");
                dateFin = Saisie::saisirDate("Saisissez la date de fin");
                service.voirStatsZone(coordonnees, rayon, dateDebut, dateFin);
                break;
            case 3:
                idPurificateur = Saisie::saisirString("Saisissez l'identifiant du purificateur");
                mesures = service.consulterImpactPurificateur(idPurificateur);
                cout << "Valeurs sur 7 jours avant l'activation du purificateur :" << endl << mesures.first << endl;
                cout << "Valeurs sur les 7 jours avant la désactivation du purificateur :" << endl << mesures.second << endl;

                break;
        }
    }while(choix != 0);

    return 0;
}