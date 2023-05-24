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

    return capteurs;
}