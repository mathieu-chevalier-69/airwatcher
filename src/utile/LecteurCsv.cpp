#include "LecteurCsv.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

vector<vector<string>> LecteurCsv::lireCsv(const string & nomFichier)
{
    ifstream fichier(nomFichier);
    vector<vector<string>> lignesFichier;
    if (fichier)
    {
        string ligne;
        while (getline(fichier, ligne))
        {
            
                std::vector<std::string> row;
                std::stringstream ss(ligne);
                std::string value;

                while (std::getline(ss, value, ';'))
                {
                    row.push_back(value);
                }

                lignesFichier.push_back(row);
        }
        fichier.close();
    }else
    {
        cerr << "Impossible d'ouvrir le fichier" << endl;
    }
    return lignesFichier;
}