#include "Service.h"
using namespace std;
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
    
    if(capteursDansZone.size() == 0){
        return Mesure(-2,-2,-2,-2);
    }

    // Variables de stockage des concentrations
    Mesure mesureMoyenne(0,0,0,0);
    int nombreMesures = 0;

    /*
    Pour chaque capteur dans la zone, on utilise la méthode obtenirStatsCapteur
    Cela nous retourne la mesureMoyenne de ce capteur sur la durée
    */
    for (Capteur capteur : capteursDansZone)
    {
        Mesure m = obtenirStatsCapteur(capteur, dateDebut, dateFin);
        if (m.concentrationNO2 != -1)
        {
            mesureMoyenne += m;
            nombreMesures++;
        }
    }

    // Calcul de la moyenne des concentration et renvoi de la mesure moyenne
    return nombreMesures > 0 ? mesureMoyenne / nombreMesures : Mesure(-1,-1,-1,-1);
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

    // Récupération du maximum
    int maximum = -1;
    if (maximum < indiceO3)
        maximum = indiceO3;
    if (maximum < indiceNO2)
        maximum = indiceNO2;
    if (maximum < indicePM10)
        maximum = indicePM10;
    if (maximum < indiceSO2)
        maximum = indiceSO2;
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

    return nombreDeMesure == 0 ? Mesure(-1, -1, -1, -1) : mesureMoyenne / nombreDeMesure;
}

pair<Mesure, Mesure> Service::consulterImpactPurificateur(string idPurificateur, int rayon)
{
    Purificateur purificateurRecupere = donnees.donneesPurificateurs.obtenirPurificateurParId(idPurificateur);
    if(purificateurRecupere.startTime.jour == -1){
        Mesure mesureTemoin(-1,-1,-1,-1);
        return make_pair(mesureTemoin,mesureTemoin);
    }
    Date debutMoins7 = purificateurRecupere.startTime - 7;
    Date debutMoins1 = purificateurRecupere.startTime - 1;
    Date finPlus1 = purificateurRecupere.stopTime - 7;
    Date finPlus7 = purificateurRecupere.stopTime - 1;

    
    Mesure avant = (*this).voirStatsZone(purificateurRecupere.coordonnees, rayon, debutMoins7, debutMoins1);
    Mesure apres = (*this).voirStatsZone(purificateurRecupere.coordonnees, rayon, finPlus1, finPlus7);

    pair<Mesure, Mesure> resultats = make_pair(avant, apres);
    return resultats;
}