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
#include <map>
#include <utility>
#include "Utilisateur.h"
//#include "Capteur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef std::map<std::string, Utilisateur > listeUtilisateurs ;
//------------------------------------------------------------------------
// Rôle de la classe <DonneesUtilisateurs>
//
//
//------------------------------------------------------------------------

class DonneesUtilisateurs 
{
//----------------------------------------------------------------- PUBLIC

public:
listeUtilisateurs listeU;
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    // 
    //Utilisateur TrouverUtilisateurParCapteur(Capteur c);
    void AjouterUtilisateurDansListe(const Utilisateur  u);
    


//------------------------------------------------- Surcharge d'opérateurs
   

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

//-------------------------------- Autres définitions dépendantes de <DonneesUtilisateurs>

#endif // DonneesUtilisateurs_H
