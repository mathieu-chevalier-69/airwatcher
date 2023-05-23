#include <iostream>
#include <string>
#include <limits>
using namespace std;

#include "Date.h"
#include "Coordonnee.h"

class Saisie{
    public:
        Saisie();
        ~Saisie();
        static Date saisirDate(string);
        static int saisirInt(string);
        static Coordonnee saisirCoordonnees(string);
};