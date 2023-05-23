#ifndef Mesure_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Mesure_H

// Inclusions des autres fichiers d'en-tête si nécessaire
using namespace std;
#include<string>
// Déclarations des constantes si nécessaire

// Déclarations des classes

class Mesure {
    public : 
        string id; 
        float valeur;
        Mesure(string id, float valeur) : id(id), valeur(valeur){};


        
        virtual ~Mesure();   


    protected : 
    

};



#endif  // Fin des directives du préprocesseur