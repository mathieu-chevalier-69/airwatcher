/*************************************************************************
                           Gouvernement  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Gouvernement> (fichier Gouvernement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Gouvernement.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Gouvernement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Gouvernement::Gouvernement ( const Gouvernement & unGouvernement )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Gouvernement>" << endl;
#endif
} //----- Fin de Gouvernement (constructeur de copie)


Gouvernement::Gouvernement (string email, string motDePasse, string identifiant,string n ) :  Utilisateur(email,motDePasse), id(identifiant), nom(n)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Gouvernement>" << endl;
#endif
} //----- Fin de Gouvernement


Gouvernement::~Gouvernement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Gouvernement>" << endl;
#endif
} //----- Fin de ~Gouvernement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
