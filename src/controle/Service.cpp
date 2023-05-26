#include"Service.h"


Mesure Service::voirStatsZone(const Coordonnees & pointCentral,const float & rayon, const Date & dateDebut,const Date & dateFin){
        

        //Récupération des capteurs dans la zone
        vector<Capteur> capteursDansZone;

        for(Capteur capteur : donnees.donneesCapteurs.listeCapteurs){
            if(capteur.coordonees.dansLeCercle(pointCentral, rayon)){
                capteursDansZone.push_back(capteur);
            }
        }

        //Variables de stockage des concentrations
        float concentrationO3 = 0;
        float concentrationSO2 = 0; 
        float concentrationPM10 = 0; 
        float concentrationNO2 = 0;
        int nombreMesures = 0;

        /*
        Pour chaque capteur dans la zone, on regarde chacune des mesures
        Pour chacune de ces mesures, on  vérifie si elle se situe dans l'intervalle de temps désiré
        Si oui, on ajoute les valeurs de ces meures dans les variables de stockage
        */
        for(Capteur capteur : capteursDansZone){
            for(auto it = capteur.mesures.begin(); it != capteur.mesures.end(); ++it){
                Date date = it->first;
                if(date < dateFin && !(date < dateDebut)){
                    Mesure mesure = it->second;
                    concentrationNO2 += mesure.concentrationNO2;
                    concentrationO3 += mesure.concentrationO3;
                    concentrationSO2 += mesure.concentrationSO2;
                    concentrationPM10 += mesure.concentrationPM10;
                    nombreMesures++;
                }
            }
        }
        
        //Calcul de la moyenne des concentration et renvoi de la mesure moyenne
        concentrationNO2 /= nombreMesures;
        concentrationO3 /= nombreMesures;
        concentrationPM10 /= nombreMesures;
        concentrationSO2 /= nombreMesures;
        
        Mesure moyenneZone (concentrationO3, concentrationNO2, concentrationSO2, concentrationPM10);
        return moyenneZone;
}