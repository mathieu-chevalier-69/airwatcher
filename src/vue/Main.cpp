#include"../utile/Date.h"
#include"../modele/Capteur.h"
#include"../modele/Mesure.h"
#include "../modele/Donnees.h"

#include <iostream>

int main(){
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
    return 0;
}