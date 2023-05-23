#ifndef Mesure_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Mesure_H

// Inclusions des autres fichiers d'en-tête si nécessaire
using namespace std;
#include<string>


class Mesures {
    public : 
        float 
        float valeur;
        Mesures(string id, float valeur) : id(id), valeur(valeur){};


        
        virtual ~Mesures();   


    protected : 
    

};



#endif  // Fin des directives du préprocesseur