#include <iostream>

using namespace std;
#include "Purificateur.h"

Purificateur::Purificateur()
{
    startTime = Date(-1,-1,-1);
}

Purificateur::Purificateur(string i, Coordonnees coords, Date debut, Date fin, string entreprise)
{
    id = i;
    coordonnees = coords;
    startTime = debut;
    stopTime = fin;
    entrepriseId = entreprise;
}

Purificateur::~Purificateur()
{

}