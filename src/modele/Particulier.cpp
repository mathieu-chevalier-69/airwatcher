/*************************************************************************
                           Particulier  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Particulier> (fichier Particulier.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Particulier.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Particulier::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Particulier::Particulier ( const Particulier & unParticulier )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Particulier>" << endl;
#endif
} //----- Fin de Particulier (constructeur de copie)


Particulier::Particulier (string email, string motDePasse, string identifiant, string cID ) : Utilisateur(email,motDePasse), id(identifiant), capteurId(cID)
// Algorithme :
//
{
    
#ifdef MAP
    cout << "Appel au constructeur de <Particulier>" << endl;
#endif
} //----- Fin de Particulier


Particulier::~Particulier ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Particulier>" << endl;
#endif
} //----- Fin de ~Particulier


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
