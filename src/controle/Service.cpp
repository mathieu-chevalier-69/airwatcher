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

int Service::calculAtmo(Mesure mesure){

    /* 
    Méthode de calcul ATMO : 
    Pour chacune des concentration (O3, SO2, NO3 et PM10), lui donner une note sur une échelle de 1 à 10
    Prendre la note maximum entre ces 4 indices et la renvoyer
    Les mesures allant jusqu'à 100, 10, la pire note correspond à une concentration de 100 µg/m3
    */

   int indiceO3 = (int)(mesure.concentrationO3/10);
   int indiceSO2 = (int)(mesure.concentrationSO2/10);
   int indiceNO2 = (int)(mesure.concentrationNO2/10);
   int indicePM10 = (int)(mesure.concentrationPM10/10);

   return max<int>({indiceO3, indiceSO2, indiceSO2, indicePM10});
}



Mesure Service::obtenirStatsCapteur(Capteur capteur, Date dateDebut, Date dateFin){
            Mesure mesureMoyenne; 
            int nombreDeMesure = 0; 
            
            for(auto it = capteur.mesures.begin(); it != capteur.mesures.end(); ++it){
                Date date = it->first;
                if(date < dateFin && !(date < dateDebut)){
                    Mesure mesure = it->second;
                    mesureMoyenne += mesure;
                }
            }

            return mesureMoyenne;

}