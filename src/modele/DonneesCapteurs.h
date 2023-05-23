/*************************************************************************
                           DonneesCapteurs  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <DonneesCapteurs> (fichier DonneesCapteurs.h) ----------------
#if ! defined ( DonneesCapteurs_H )
#define DonneesCapteurs_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DonneesCapteurs>
//
//
//------------------------------------------------------------------------

class DonneesCapteurs 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    DonneesCapteurs & operator = ( const DonneesCapteurs & unDonneesCapteurs );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    DonneesCapteurs( const DonneesCapteurs& unDonneesCapteurs);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    DonneesCapteurs( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DonneesCapteurs( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <DonneesDonneesDonneesCapteursss>

#endif // DonneesDonneesDonneesCapteursss_H
