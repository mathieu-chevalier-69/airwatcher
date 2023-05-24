#include "FluxImport.h"
#include "../utile/LecteurCsv.h"
#include "Capteur.h"
#include <vector>
#include <iostream>

using namespace std;


vector<Capteur> FluxImport::importerCapteurs()
{
    //Chargement des capteurs et affectation de base au gouvernement
    vector<vector<string>> donnees = LecteurCsv::lireCsv("./dataset/sensors.csv");

    vector<vector<string>>::const_iterator iterateur;
    vector<Capteur> capteurs;

    for(iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        Capteur capteur((*iterateur)[0], stof((*iterateur)[2]),stof((*iterateur)[1]),"gouvernement");
        capteurs.push_back(capteur);
    }
    //Affectation des capteurs privés aux utilisateurs
    donnees = LecteurCsv::lireCsv("./dataset/users.csv");
    for(iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        vector<Capteur>::iterator capteur;
        for(capteur = capteurs.begin(); capteur < capteurs.end(); capteur++)
        {
            if((*iterateur)[1] == (capteur->id))
                capteur->proprietaire = (*iterateur)[0];
            break;
        }
    }

    //Chargement des mesures
    donnees = LecteurCsv::lireCsv("./dataset/measurements.csv");
    map<string, map<Date, Mesure>> mesures;
    for(iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        Date date((*iterateur)[0]);
        if(mesures.find( (*iterateur)[1] ) != mesures.end())
        {
            //Le capteur ID existe déjà
            if(mesures[(*iterateur)[1]].find( date ) != mesures[(*iterateur)[1]].end())
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
            //Le capteur ID existe pas
            Mesure mesure;
            mesure.setAttribute((*iterateur)[2], stof((*iterateur)[3]));
            map<Date, Mesure> donneesCapteur;
            donneesCapteur.insert({date, mesure});
            mesures.insert({(*iterateur)[1], donneesCapteur});
        }
    }

    vector<Capteur>::iterator capteur;
    for(capteur = capteurs.begin(); capteur < capteurs.end(); capteur++)
    {
        if(mesures.find( capteur->id ) != mesures.end())
            capteur->mesures = mesures[capteur->id];
    }

    return capteurs;
}