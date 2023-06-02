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
    // Mesure m(2,1,1,1);
    // Date d(1,2,2023);
    // Capteur c("Hey", 1, 1, "moi");
    // c.ajouterMesure(m , d);
    // Date d1(1,2,2024);
    // Mesure m1(3,1,1,1);
    // c.ajouterMesure(m1 , d1);
    // Date date = c.mesures.cbegin()->first;
    // Mesure mesure = c.mesures.cbegin()->second;
    // cout << "jour : " << date.jour << "mois : " << date.mois << "annee : " << date.annee << endl;
    // cout << "3 :" << mesure.concentrationO3 << " 1 : " << mesure.concentrationSO2 << endl;

    // Date date1 = (++c.mesures.cbegin())->first;
    // Mesure mesure1 = (++c.mesures.cbegin())->second;
    // cout << "jour : " << date1.jour << "mois : " << date1.mois << "annee : " << date1.annee << endl;
    // cout << "2 :" << mesure1.concentrationO3 << " 1 : " << mesure1.concentrationSO2 << endl;

    Service service; 
    // Date debut(27,12,2019);
    // Date fin(31,12,2019);
    // cout << "Moyenne :"<<service.obtenirStatsCapteur(service.donnees.donneesCapteurs.listeCapteurs[0], debut, fin) << endl;
    //Test::testerCapteurDansZone();
    cout << service.donnees.donneesCapteurs.listeCapteurs.size() << endl;
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
                //pair<Mesure, Mesure> mesures = service.consulterImpactPurificateur(idPurificateur);
                break;
        }
    }while(choix != 0);

    return 0;
}