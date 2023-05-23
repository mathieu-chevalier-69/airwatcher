/*************************************************************************
                           Particulier  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Particulier> (fichier Particulier.h) ----------------
#if ! defined ( Particulier_H )
#define Particulier_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Particulier>
//
//
//------------------------------------------------------------------------

class Particulier : Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
string id;
string capteurId;
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Particulier & operator = ( const Particulier & unParticulier );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Particulier ( const Particulier & unParticulier );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Particulier (string email, string motDePasse, string identifiant, string cID ) : Utilisateur(email,motDePasse), id(identifiant), capteurId(cId);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Particulier ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Particulier>

#endif // Particulier_H
