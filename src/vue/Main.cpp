#include "../utile/Date.h"
#include "../modele/Capteur.h"
#include "../modele/Mesure.h"
#include "../modele/Donnees.h"
#include "../controle/Service.h"
#include <iostream>

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


    Donnees donnees;
    cout << donnees.donneesCapteurs.listeCapteurs.size() << endl;

    for (map<Date, Mesure>::const_iterator it = donnees.donneesCapteurs.listeCapteurs[0].mesures.begin();
    it != donnees.donneesCapteurs.listeCapteurs[0].mesures.end(); ++it)
    {
        cout << it->first << " " << it->second << "\n";
    }

    cout << donnees.donneesCapteurs.capteurDansZone(Coordonnees(45.3333,1.3333), 200).size() << endl;

   /*
    Coordonnees c1(45.3333f,1.333f);
    Coordonnees c2(46.66f,3.66f);
    cout << Coordonnees::distance(c1,c2) << endl;*/

    Service service; 
    Date debut(27,12,2019);
    Date fin(31,12,2019);
    cout << "Moyenne :"<<service.obtenirStatsCapteur(donnees.donneesCapteurs.listeCapteurs[0], debut, fin) << endl;
    return 0;
}