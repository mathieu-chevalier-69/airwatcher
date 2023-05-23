/*************************************************************************
                           DonneesUtilisateurs  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <DonneesUtilisateurs> (fichier DonneesUtilisateurs.h) ----------------
#if ! defined ( DonneesUtilisateurs_H )
#define DonneesUtilisateurs_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DonneesUtilisateurs>
//
//
//------------------------------------------------------------------------

class DonneesUtilisateurs 
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
    DonneesUtilisateurs & operator = ( const DonneesUtilisateurs & unDonneesUtilisateurs );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    DonneesUtilisateurs( const DonneesUtilisateurs& unDonneesUtilisateurs);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    DonneesUtilisateurs( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DonneesUtilisateurs( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <DonneesDonneesDonneesUtilisateursss>

#endif // DonneesDonneesDonneesUtilisateursss_H
