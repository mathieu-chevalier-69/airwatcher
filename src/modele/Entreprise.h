/*************************************************************************
                           Entreprise  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Entreprise> (fichier Entreprise.h) ----------------
#if ! defined ( Entreprise_H )
#define Entreprise_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Entreprise>
//
//
//------------------------------------------------------------------------

class Entreprise : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:

string id;
string purificateurId;
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
  


//-------------------------------------------- Constructeurs - destructeur
    Entreprise ( const Entreprise & unEntreprise );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Entreprise (string email, string motDePasse, string identifiant, string purifiId );
   
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Entreprise ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Entreprise>

#endif // Entreprise_H
