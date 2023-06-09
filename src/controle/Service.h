#ifndef Service_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Service_H


#include<iostream>

#include "../modele/Donnees.h"
#include "../utile/Saisie.h"

class Service{

    public : 
        //Attributs de la classe
        Donnees donnees;

        //Constructeurs et destructeurs de classe
        Service(){};
        Service(const Donnees & donnees) : donnees(donnees){};
        virtual ~Service(){};

        //Methodes de la classe 
        Mesure voirStatsZone(const Coordonnees & pointCentral,const float & rayon,const Date & dateDebut,const Date & dateFin);

        pair<Mesure, Mesure> consulterImpactPurificateur(std::string idPurificateur, int rayon);

        std::vector<Capteur> voirCapteursStatsSimilaires(std::string idCapteur);

        Mesure voirStatsSurUnPoint(Coordonnees point); 
        Mesure obtenirStatsCapteur(Capteur capteur, Date dateDebut, Date dateFin);
        int calculAtmo(Mesure); 


};

#endif