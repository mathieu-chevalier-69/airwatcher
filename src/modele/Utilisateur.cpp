/*************************************************************************
                           Utilisateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Utilisateur> (fichier Utilisateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Utilisateur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Utilisateur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Utilisateur::Utilisateur ( const Utilisateur & unUtilisateur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur (constructeur de copie)


Utilisateur::Utilisateur ( string mail, string mdp )
// Algorithme :
//
{
    email = mail;
    motDePasse = mdp;

#ifdef MAP
    cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur

Utilisateur::Utilisateur ( )
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de Utilisateur

Utilisateur::~Utilisateur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de ~Utilisateur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
