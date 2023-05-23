#ifndef Purificateur_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Purificateur_H

#include <iostream>
#include <string>
using namespace std;

#include "../utile/Coordonnees.h"
#include "../utile/Date.h"

class Purificateur{
    public:

        Purificateur();
        Purificateur(string, Coordonnees, Date,Date,string);

        string id;
        Coordonnees coordonnees;
        Date startTime;
        Date stopTime;
        string entrepriseId;


        virtual ~Purificateur();
};


#endif