/*************************************************************************
                           Entreprise  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Entreprise> (fichier Entreprise.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Entreprise.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Entreprise::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Entreprise & Entreprise::operator = ( const Entreprise & unEntreprise )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Entreprise::Entreprise ( const Entreprise & unEntreprise )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Entreprise>" << endl;
#endif
} //----- Fin de Entreprise (constructeur de copie)


Entreprise::Entreprise (string email, string motDePasse, string identifiant, string purifiId ) : Utilisateur(email,motDePasse), id(identifiant), purificateurId(purifiId)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Entreprise>" << endl;
#endif
} //----- Fin de Entreprise


Entreprise::~Entreprise ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Entreprise>" << endl;
#endif
} //----- Fin de ~Entreprise


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
