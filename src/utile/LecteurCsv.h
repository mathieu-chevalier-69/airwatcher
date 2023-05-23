/*************************************************************************
                           LecteurCsv  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LecteurCsv> (fichier LecteurCsv.h) ----------------
#if ! defined ( LecteurCsv_H )
#define LecteurCsv_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LecteurCsv>
//
//
//------------------------------------------------------------------------

class LecteurCsv 
{
//----------------------------------------------------------------- PUBLIC

public:

    static std::vector<std::vector<std::string> > lireCsv(const std::string nomFichier);
    static std::vector<std::string> separer(const std::string chaine, char separateur);

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <LecteurCsv>

#endif // LecteurCsv_H
