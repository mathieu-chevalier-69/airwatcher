#include <iostream>
#include <string>
#include "Date.h"
#include "Coordonnee.h"

class Saisie{
    public:
        Saisie();
        ~Saisie();
        static Date saisirDate(String);
        static int saisirInt(String);
        static Coordonnee saisirCoordonnees(String);
}