#include "Service.h"

Mesure Service::voirStatsZone(const Coordonnees &pointCentral, const float &rayon, const Date &dateDebut, const Date &dateFin)
{

    // Récupération des capteurs dans la zone
    vector<Capteur> capteursDansZone;

    for (Capteur capteur : donnees.donneesCapteurs.listeCapteurs)
    {
        if (capteur.coordonees.dansLeCercle(pointCentral, rayon))
        {
            capteursDansZone.push_back(capteur);
        }
    }

    // Variables de stockage des concentrations
    Mesure mesureMoyenne;
    int nombreMesures = 0;

    /*
    Pour chaque capteur dans la zone, on utilise la méthode obtenirStatsCapteur
    Cela nous retourne la mesureMoyenne de ce capteur sur la durée
    */
    for (Capteur capteur : capteursDansZone)
    {
        mesureMoyenne += obtenirStatsCapteur(capteur,dateDebut,dateFin);
        nombreMesures++;
    }

    // Calcul de la moyenne des concentration et renvoi de la mesure moyenne  
    return mesureMoyenne/nombreMesures;
}

int Service::calculAtmo(Mesure mesure)
{

    /*
    Méthode de calcul ATMO :
    Pour chacune des concentration (O3, SO2, NO3 et PM10), lui donner une note sur une échelle de 1 à 10
    Prendre la note maximum entre ces 4 indices et la renvoyer
    Les mesures allant jusqu'à 100, 10, la pire note correspond à une concentration de 100 µg/m3
    */

    int indiceO3 = (int)(mesure.concentrationO3 / 10);
    int indiceSO2 = (int)(mesure.concentrationSO2 / 10);
    int indiceNO2 = (int)(mesure.concentrationNO2 / 10);
    int indicePM10 = (int)(mesure.concentrationPM10 / 10);

    //Récupération du maximum
    int maximum = -1;
    if(maximum < indiceO3) maximum = indiceO3;
    if(maximum < indiceNO2) maximum = indiceNO2;
    if(maximum < indicePM10) maximum = indicePM10;
    if(maximum < indiceSO2) maximum = indiceSO2;
    return maximum;
}

Mesure Service::obtenirStatsCapteur(Capteur capteur, Date dateDebut, Date dateFin)
{
    Mesure mesureMoyenne;
    int nombreDeMesure = 0;

    for (auto it = capteur.mesures.begin(); it != capteur.mesures.end(); ++it)
    {
        Date date = it->first;
        if ((date < dateFin || date == dateFin) && !(date < dateDebut))
        {
            Mesure mesure = it->second;
            mesureMoyenne += mesure;
            nombreDeMesure++;
        }
    }

    return mesureMoyenne / nombreDeMesure;
}

// pair<Mesure, Mesure> consulterImpactPurificateur(string idPurificateur)
// {
//     Purificateur purificateurRecupere = donnees.donneesPurificateur.obtenirPurificateurParId(idPurificateur);
//     Date debutMoins7 = 
//     Date debutMoins1 = 
//     Date finPlus1 = 
//     Date finPlus7 =

// }