#if ! defined ( Coordonnees_H )
#define Coordonnees_H


//La classe coordonnees permet de gérer des points avec des coordonnees et de réaliser des opérations dessus

#include <cmath>

class Coordonnees 
{

public:

    //Attributs de la classe
    float latitude;
    float longitude;

    //Constructeurs -- Destructeurs
    Coordonnees ( );
    Coordonnees ( const float latitude, const float longitude );
    virtual ~Coordonnees ( );

    //Surcharge d'opérateur
    friend std::ostream& operator<<(std::ostream& os, const Coordonnees& coordonnees);

    //Méthodes membre de la classe
    bool dansLeCercle(Coordonnees centreCercle, float rayon);
    static float distance(Coordonnees pointA, Coordonnees pointB);
};

#endif // Coordonnees_H
