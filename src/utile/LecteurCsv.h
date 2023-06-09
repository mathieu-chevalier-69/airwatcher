
#if ! defined ( LecteurCsv_H )
#define LecteurCsv_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>

class LecteurCsv 
{
//----------------------------------------------------------------- PUBLIC

public:

    static std::vector<std::vector<std::string> > lireCsv(const std::string& nomFichier);

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <LecteurCsv>

#endif // LecteurCsv_H
