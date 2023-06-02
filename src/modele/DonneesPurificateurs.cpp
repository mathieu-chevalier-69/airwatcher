/*************************************************************************
                           DonneesPurificateurs  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <DonneesPurificateurs> (fichier DonneesPurificateurs.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "DonneesPurificateurs.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC


DonneesPurificateurs::DonneesPurificateurs ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DonneesPurificateurs>" << endl;
#endif
} //----- Fin de DonneesPurificateurs


DonneesPurificateurs::~DonneesPurificateurs ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DonneesPurificateurs>" << endl;
#endif
} //----- Fin de ~DonneesPurificateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
