#ifndef Service_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Service_H


using namespace std;
#include<iostream>

#include"../modele/Donnees.h"

class Service{

    public : 
        Donnees donnees;

        Service(const Donnees & donnees) : donnees(donnees){};

        Mesure voirStatsZone(const Coordonnees & pointCentral,const float & rayon,const Date & dateDebut,const Date & dateFin);
        pair<Mesure, Mesure> consulterImpactPurificateur(string idPurificateur);
        vector<Capteur> voirCapteursStatsSimilaires(string idCapteur);
        Mesure voirStatsSurUnPoint(Coordonnees point); 
        Mesure obtenirStatsCapteur(Capteur capteur);
        int calculAtmo(Mesure); 

};

#endif