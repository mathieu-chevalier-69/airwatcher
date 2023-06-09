
#if ! defined ( DonneesPurificateurs_H )
#define DonneesPurificateurs_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include "Purificateur.h"

//------------------------------------------------------------- Constantes
#include<vector>

typedef vector<Purificateur> ListePurificateur;
class DonneesPurificateurs 
{
//----------------------------------------------------------------- PUBLIC

public:
    ListePurificateur listePurificateurs;
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    DonneesPurificateurs( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Purificateur obtenirPurificateurParId(string idPurificateur);

    virtual ~DonneesPurificateurs( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <DonneesDonneesDonneesPurificateursss>

#endif // DonneesDonneesDonneesPurificateursss_H
