#ifndef Date_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Date_H

// Inclusions des autres fichiers d'en-tête si nécessaire
using namespace std;
#include<string>


class Date {
    public : 
        int jour;
        int mois; 
        int annee; 
        Date(int jour, int mois, int annee) 
        : jour(jour), mois(mois), annee(annee) {};

        bool operator<(const Date& autreDate) const;
        bool operator==(const Date& autreDate) const;

        
        virtual ~Date();   


    protected : 
    

};



#endif  // Fin des directives du préprocesseur