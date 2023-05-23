#include"../utile/Date.h"
#include"../modele/Capteur.h"
#include"../modele/Mesure.h"

#include<iostream>
int main(){
    Mesure m(2,1,1,1);
    Date d(1,2,2023);
    Capteur c("Hey", 1, 1, "moi"); 
    c.ajouterMesure(m , d);
    Date date = c.mesures.cbegin()->first;
    Mesure mesure = c.mesures.cbegin()->second;
    cout << "jour : " << date.jour << "mois : " << date.mois << "annee : " << date.annee << endl; 
    cout << "2 :" << mesure.concentrationO3 << " 1 : " << mesure.concentrationSO2 << endl;
    
    return 0;
}