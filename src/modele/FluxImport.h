/*************************************************************************
                           FluxImport  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <FluxImport> (fichier FluxImport.h) ----------------
#if ! defined ( FluxImport_H )
#define FluxImport_H

//--------------------------------------------------- Interfaces utilisées
#include "Capteur.h"
#include "Purificateur.h"
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <FluxImport>
//
//
//------------------------------------------------------------------------

class FluxImport
{
//----------------------------------------------------------------- PUBLIC

public:

    static vector<Capteur> importerCapteurs();
    static vector<Purificateur> importerPurificateurs();

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <FluxImport>

#endif // FluxImport_H
