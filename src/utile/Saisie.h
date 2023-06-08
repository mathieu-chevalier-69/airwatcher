#ifndef Saisie_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Saisie_H

#include <iostream>
#include <string>
#include <limits>
using namespace std;

#include "Date.h"
#include "Coordonnees.h"

class Saisie{
    public:
        Saisie();
        ~Saisie();
        static Date saisirDate(string);
        static int saisirInt(const std::string& message);
        static Coordonnees saisirCoordonnees(string);
        static string saisirString(string);
};

#endif