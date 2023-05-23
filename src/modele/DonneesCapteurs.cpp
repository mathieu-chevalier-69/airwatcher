/*************************************************************************
                           DonneesCapteurs  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <DonneesCapteurs> (fichier DonneesCapteurs.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "DonneesCapteurs.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type DonneesCapteurs::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
DonneesCapteurs & DonneesCapteurs::operator = ( const DonneesCapteurs & unDonneesCapteurs )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
DonneesCapteurs::DonneesCapteurs ( const DonneesCapteurs & unDonneesCapteurs )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <DonneesCapteurs>" << endl;
#endif
} //----- Fin de DonneesCapteurs (constructeur de copie)


DonneesCapteurs::DonneesCapteurs ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DonneesCapteurs>" << endl;
#endif
} //----- Fin de DonneesCapteurs


DonneesCapteurs::~DonneesCapteurs ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DonneesCapteurs>" << endl;
#endif
} //----- Fin de ~DonneesCapteurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
