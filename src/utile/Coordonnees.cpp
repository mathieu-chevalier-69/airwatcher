/*************************************************************************
                           Coordonnees  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Coordonnees> (fichier Coordonnees.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Coordonnees.h"
#include <cmath>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Coordonnees::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Coordonnees::Coordonnees ( const float latitude, const float longitude )
:latitude(latitude),longitude(longitude)
{
}

Coordonnees::Coordonnees ( )
:latitude(0), longitude(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Coordonnees>" << endl;
#endif
} //----- Fin de Coordonnees


Coordonnees::~Coordonnees ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Coordonnees>" << endl;
#endif
} //----- Fin de ~Coordonnees

bool Coordonnees::dansLeCercle(Coordonnees centreCercle, float rayon)
{
    float distance = Coordonnees::distance(*this, centreCercle);
    return distance <= rayon;
}

float Coordonnees::distance(Coordonnees pointA, Coordonnees pointB)
{
    float deltaLongitude = pointB.longitude - pointA.longitude;

    float distance = acos(sin(pointA.latitude)*sin(pointB.latitude)+cos(pointA.latitude)*cos(pointB.latitude)*cos(deltaLongitude));
    distance *= 6378137;

    return distance;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
