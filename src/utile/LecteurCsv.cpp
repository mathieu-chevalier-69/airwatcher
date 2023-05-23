#include "LecteurCsv.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

std::vector<std::vector<std::string> > LecteurCsv::lireCsv(string nomFichier)
{
    ifstream fichier(nomFichier);
    vector<vector<string> > lignesFichier;
    if(fichier)
    {
        string ligne;
        bool premiereLigne = true;
        while(getline(fichier, ligne)){
            if(!premiereLigne){
                lignesFichier.push_back(separer(ligne, ','));
            }else{
                premiereLigne = false;
            }
        }
    }
    return lignesFichier;
}

std::vector<std::string> separer(const string& str, char separateur)
{
    vector<std::string> morceaux;
    stringstream ss(str);
    string morceau;

    while (getline(ss, morceau, separateur)) {
        morceaux.push_back(morceau);
    }

    return morceaux;
}
