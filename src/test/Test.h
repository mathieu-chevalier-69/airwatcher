#ifndef Test_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Test_H

#include <iostream>
#include <string>
using namespace std;

#include "../controle/Service.h"

class Test{
    public:
        //Constructeur - Destructeur
        Test(){};
        ~Test(){};

        //Méthodes de test
        static bool testerCapteurDansZone();
        static bool testerMesurerEfficacitéPurificateur();
};

#endif