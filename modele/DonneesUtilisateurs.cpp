/*************************************************************************
                           DonneesUtilisateurs  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <DonneesUtilisateurs> (fichier DonneesUtilisateurs.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "DonneesUtilisateurs.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type DonneesUtilisateurs::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
DonneesUtilisateurs & DonneesUtilisateurs::operator = ( const DonneesUtilisateurs & unDonneesUtilisateurs )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
DonneesUtilisateurs::DonneesUtilisateurs ( const DonneesUtilisateurs & unDonneesUtilisateurs )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <DonneesUtilisateurs>" << endl;
#endif
} //----- Fin de DonneesUtilisateurs (constructeur de copie)


DonneesUtilisateurs::DonneesUtilisateurs ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DonneesUtilisateurs>" << endl;
#endif
} //----- Fin de DonneesUtilisateurs


DonneesUtilisateurs::~DonneesUtilisateurs ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DonneesUtilisateurs>" << endl;
#endif
} //----- Fin de ~DonneesUtilisateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
