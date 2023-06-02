#ifndef Date_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Date_H

// Inclusions des autres fichiers d'en-tête si nécessaire
using namespace std;
#include <string>
#include <iostream>

class Date {
    public : 
        //Attributs de date
        int jour;
        int mois; 
        int annee; 

        //Constructeurs, Destructeurs
        Date();
        Date(const int jour, const int mois, const int annee) 
        : jour(jour), mois(mois), annee(annee) {};
        Date(string);
        
        virtual ~Date();   

        //Surchages d'opérateur
        friend ostream& operator <<(ostream & os, const Date date);
        bool operator<(const Date& autreDate) const;
        bool operator==(const Date& autreDate) const;
        Date operator-(int jours)const;
        bool estAnneeBissextile(int annee)const;
        int getJoursDansMois(int mois, int annee)const;
    
};



#endif  // Fin des directives du préprocesseur