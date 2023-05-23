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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Gouvernement>
//
//
//------------------------------------------------------------------------

class Gouvernement 
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

    Gouvernement ( );
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
