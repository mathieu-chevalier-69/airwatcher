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


Purificateur DonneesPurificateurs::obtenirPurificateurParId(string idPurificateur)
{
    
    Purificateur purificateurRecupere;
    // for(iterator<Purificateur> it = listePurificateurs.begin(); it != listePurificateurs.end(); ++it)
    // {
    //     if (it->id == idPurificateur)
    //     {
    //         purificateurRecupere = *it;
    //         return purificateurRecupere;
    //     }
    // }
    return purificateurRecupere;
}



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
