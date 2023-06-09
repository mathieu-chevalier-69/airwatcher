#include "FluxImport.h"
#include "../utile/LecteurCsv.h"
#include "Capteur.h"
#include "Entreprise.h"
#include "Mesure.h"
#include <vector>
#include <iostream>

using namespace std;

vector<Capteur> FluxImport::importerCapteurs(string cheminDossier)
{
    // Chargement des capteurs et affectation de base au gouvernement
    vector<vector<string>> donnees = LecteurCsv::lireCsv(cheminDossier + "sensors.csv");

    vector<vector<string>>::const_iterator iterateur;
    vector<Capteur> capteurs;

    for (iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        Capteur capteur((*iterateur)[0], stof((*iterateur)[2]), stof((*iterateur)[1]), "gouvernement");
        capteurs.push_back(capteur);
    }
    // Affectation des capteurs privés aux utilisateurs
    donnees = LecteurCsv::lireCsv(cheminDossier + "users.csv");
    for (iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        vector<Capteur>::iterator capteur;
        for (capteur = capteurs.begin(); capteur < capteurs.end(); capteur++)
        {
            if ((*iterateur)[1] == (capteur->id))
            {
                capteur->proprietaire = (*iterateur)[0];
                break;
            }
        }
    }

    // Chargement des mesures
    donnees = LecteurCsv::lireCsv(cheminDossier + "measurements.csv");
    map<string, map<Date, Mesure>> mesures;
    for (iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        Date date((*iterateur)[0]);
        if (mesures.find((*iterateur)[1]) != mesures.end())
        {
            // Le capteur ID existe déjà
            if (mesures[(*iterateur)[1]].find(date) != mesures[(*iterateur)[1]].end())
            {
                // La date existe déjà
                mesures[(*iterateur)[1]][date].setAttribute((*iterateur)[2], stof((*iterateur)[3]));
            }
            else
            {
                // La date existe pas
                Mesure mesure;
                mesure.setAttribute((*iterateur)[2], stof((*iterateur)[3]));
                mesures[(*iterateur)[1]].insert({date, mesure});
            }

        }
        else
        {

            // Le capteur ID existe pas
            Mesure mesure;
            mesure.setAttribute((*iterateur)[2], stof((*iterateur)[3]));
            map<Date, Mesure> donneesCapteur;
            donneesCapteur.insert({date, mesure});
            mesures.insert({(*iterateur)[1], donneesCapteur});
        }
    }

    vector<Capteur>::iterator capteur;
    for (capteur = capteurs.begin(); capteur < capteurs.end(); capteur++)
    {
        if (mesures.find(capteur->id) != mesures.end())
            capteur->mesures = mesures[capteur->id];
    }

    return capteurs;
}

void FluxImport::retirerCapteursErrones(vector<Capteur> & capteurs, float margeErreur)
{
    vector<Capteur>::iterator capteur;

    for (capteur = capteurs.begin(); capteur < capteurs.end(); capteur++)
    {
        if (capteur->proprietaire != "gouvernement")
        {
            Mesure moyenne;
            // C'est un capteur privé -> on le vérifie

            MapMesures::iterator mesure;
            int nbMesures = 0;
            int nbEchec = 0;
            for (Capteur capteurGouvernement : capteurs)
            {
                // On fait la moyenne des mesures des capteurs gouvernementaux dans un rayon de 150km autour
                if (capteurGouvernement.proprietaire == "gouvernement")
                {
                    if (capteurGouvernement.coordonees.dansLeCercle(capteur->coordonees, 150))
                    {
                        for (mesure = capteurGouvernement.mesures.begin(); mesure != capteurGouvernement.mesures.end(); mesure++)
                        {

                            moyenne.concentrationO3 += mesure->second.concentrationO3;
                            moyenne.concentrationNO2 += mesure->second.concentrationNO2;
                            moyenne.concentrationPM10 += mesure->second.concentrationPM10;
                            moyenne.concentrationSO2 += mesure->second.concentrationSO2;
                            nbMesures++;
                        }
                    }
                }
            }

            moyenne.concentrationO3 /= nbMesures;
            moyenne.concentrationNO2 /= nbMesures;
            moyenne.concentrationPM10 /= nbMesures;
            moyenne.concentrationSO2 /= nbMesures;
            for (mesure = capteur->mesures.begin(); mesure != capteur->mesures.end(); mesure++)
            {
                //On compte le nombre d'échecs, càd le nombre de concentrations dont la différence avec la moyenne est supérieure à la marge d'erreur
                if (abs(mesure->second.concentrationO3 - moyenne.concentrationO3) > margeErreur)
                {
                    nbEchec++;
                }
                else if (abs(mesure->second.concentrationNO2 - moyenne.concentrationNO2) > margeErreur)
                {
                    nbEchec++;
                }
                else if (abs(mesure->second.concentrationPM10 - moyenne.concentrationPM10) > margeErreur)
                {
                    nbEchec++;
                }
                else if (abs(mesure->second.concentrationSO2 - moyenne.concentrationSO2) > margeErreur)
                {
                    nbEchec++;
                }
            }
            if(((float)nbEchec) / capteur->mesures.size() > 0.05)
            {
                // Si plus de 5% des mesures du capteur dépassent la marge d'erreur, on retire le capteur
                cout << "Le capteur "<< capteur->id << " a un taux d'échec de " << (((float)nbEchec) / capteur->mesures.size())*100 <<  "% pour une marge d'erreur de " << margeErreur <<"µg/m3 il n'a pas été importé." << endl;
                capteurs.erase(capteur);
            }
        }
    }
}

vector<Purificateur> FluxImport::importerPurificateurs(string cheminDossier)
{
    vector<vector<string>> donnees = LecteurCsv::lireCsv(cheminDossier + "cleaners.csv");
    vector<vector<string>>::const_iterator iterateur;
    vector<Purificateur> purificateurs;

    for (iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        Purificateur purificateur((*iterateur)[0], Coordonnees(stof((*iterateur)[1]), stof((*iterateur)[2])), Date((*iterateur)[3]), Date((*iterateur)[4]), "");
        purificateurs.push_back(purificateur);
    }
    donnees = LecteurCsv::lireCsv(cheminDossier + "providers.csv");

    for (iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        vector<Purificateur>::iterator purificateur;
        for (purificateur = purificateurs.begin(); purificateur < purificateurs.end(); purificateur++)
        {
            if ((*iterateur)[1] == (purificateur->id))
                purificateur->entrepriseId = (*iterateur)[0];
            break;
        }
    }

    return purificateurs;
}