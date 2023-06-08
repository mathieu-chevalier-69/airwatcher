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
        static Date saisirDate(string message);
        static int saisirInt(const std::string& message);
        static Coordonnees saisirCoordonnees(string message);
        static string saisirString(string message);
};

#endif