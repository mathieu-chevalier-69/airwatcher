#if ! defined ( DonneesCapteurs_H )
#define DonneesCapteurs_H

#include "Capteur.h"
#include <vector>

typedef vector<Capteur> ListeCapteurs;
typedef vector<Mesure> ListeMesures;

class DonneesCapteurs 
{

public:
//-------------------------------------------- Attributs
    ListeCapteurs listeCapteurs;

//-------------------------------------------- Méthodes publiques

    ListeCapteurs capteurDansZone(const Coordonnees & centre, const float & rayon = 20);
    ListeMesures trouverMesures(const string & idCapteur, const Date & dateDebut, const Date & dateFin);
    Capteur & trouverCapteurParId(const string & idCapteur);

//-------------------------------------------- Constructeurs - destructeur
    DonneesCapteurs(const ListeCapteurs & listeCapteurs) 
    : listeCapteurs(listeCapteurs) {} ; 
    DonneesCapteurs();
    
    virtual ~DonneesCapteurs( );
    
};

//-------------------------------- Autres définitions dépendantes de <DonneesDonneesDonneesCapteursss>

#endif // DonneesDonneesDonneesCapteursss_H
