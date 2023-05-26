/*************************************************************************
                           Coordonnees  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Coordonnees> (fichier Coordonnees.h) ----------------
#if ! defined ( Coordonnees_H )
#define Coordonnees_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Coordonnees>
//
//
//------------------------------------------------------------------------

class Coordonnees 
{
//----------------------------------------------------------------- PUBLIC

public:
    float latitude;
    float longitude;
//-------------------------------------------- Constructeurs - destructeur

    Coordonnees ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Coordonnees ( const float latitude, const float longitude );


    virtual ~Coordonnees ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool dansLeCercle(Coordonnees centreCercle, float rayon);

    static float distance(Coordonnees pointA, Coordonnees pointB);
    friend ostream& operator<<(ostream& os, const Coordonnees& coordonnees);
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Coordonnees>

#endif // Coordonnees_H
