#include "FluxImport.h"
#include "../utile/LecteurCsv.h"
#include "Capteur.h"
#include "Entreprise.h"
#include <vector>
#include <iostream>

using namespace std;


vector<Capteur> FluxImport::importerCapteurs(string cheminDossier)
{
    //Chargement des capteurs et affectation de base au gouvernement
    string cheminFichierCapteur = cheminDossier + "sensors.csv";
    vector<vector<string>> donnees = LecteurCsv::lireCsv(cheminFichierCapteur);

    vector<vector<string>>::const_iterator iterateur;
    vector<Capteur> capteurs;

    for(iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        Capteur capteur((*iterateur)[0], stof((*iterateur)[2]),stof((*iterateur)[1]),"gouvernement");
        capteurs.push_back(capteur);
    }
    //Affectation des capteurs privés aux utilisateurs
    string cheminFichierUtilisateur = cheminDossier + "users.csv";
    donnees = LecteurCsv::lireCsv(cheminFichierUtilisateur);
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

vector<Purificateur> FluxImport::importerPurificateurs()
{
    vector<vector<string>> donnees = LecteurCsv::lireCsv("./dataset/cleaners.csv");
    vector<vector<string>>::const_iterator iterateur;
    vector<Purificateur> purificateurs;

    for(iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        Purificateur purificateur((*iterateur)[0], Coordonnees(stof((*iterateur)[1]),stof((*iterateur)[2])), Date((*iterateur)[3]),Date((*iterateur)[4]), "");
        purificateurs.push_back(purificateur);
    }
    donnees = LecteurCsv::lireCsv("./dataset/providers.csv");

    for(iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        vector<Purificateur>::iterator purificateur;
        for(purificateur = purificateurs.begin(); purificateur < purificateurs.end(); purificateur++)
        {
            if((*iterateur)[1] == (purificateur->id))
                purificateur->entrepriseId = (*iterateur)[0];
            break;
        }
    }


    return purificateurs;
}