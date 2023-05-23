/*************************************************************************
                           Gouvernement  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Gouvernement> (fichier Gouvernement.h) ----------------
#if ! defined ( Gouvernement_H )
#define Gouvernement_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Gouvernement>
//
//
//------------------------------------------------------------------------

class Gouvernement : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:

string id;
string nom;
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Gouvernement & operator = ( const Gouvernement & unGouvernement );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Gouvernement ( const Gouvernement & unGouvernement );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Gouvernement (string email, string motDePasse, string identifiant, string n );
   
    
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Gouvernement ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Gouvernement>

#endif // Gouvernement_H
