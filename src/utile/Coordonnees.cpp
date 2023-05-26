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
    // Rayon de la Terre en kilomètres
    const float rayonTerre = 6371.0;

    // Conversion des latitudes et longitudes en radians
    float latA = pointA.latitude * M_PI / 180.0;
    float lonA = pointA.longitude * M_PI / 180.0;
    float latB = pointB.latitude * M_PI / 180.0;
    float lonB = pointB.longitude * M_PI / 180.0;

    // Calcul des différences de latitudes et longitudes
    float deltaLat = latB - latA;
    float deltaLon = lonB - lonA;

    // Calcul de la distance géodésique
    float a = sin(deltaLat / 2) * sin(deltaLat / 2) +
              cos(latA) * cos(latB) *
              sin(deltaLon / 2) * sin(deltaLon / 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    float distance = rayonTerre * c;

    return distance;
}

ostream& operator<<(ostream& os, const Coordonnees& coordonnees){
    os << "Latitude : " << coordonnees.latitude << ", Longitude : " << coordonnees.longitude;
    return os;
}