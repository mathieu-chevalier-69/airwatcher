#if ! defined ( Utilisateur_H )
#define Utilisateur_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

class Utilisateur 
{
//----------------------------------------------------------------- PUBLIC

public:
string email;
string motDePasse;

//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
   


//-------------------------------------------- Constructeurs - destructeur
    Utilisateur ( const Utilisateur & unUtilisateur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Utilisateur ( string email, string motDePasse  );
    // Mode d'emploi :
    //
    // Contrat :
    //

     Utilisateur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual ~Utilisateur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Utilisateur>

#endif // Utilisateur_H
