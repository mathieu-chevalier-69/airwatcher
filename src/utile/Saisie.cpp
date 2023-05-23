#include <iostream>
using namespace std;

#include "Saisie.h"


Date Saisie::saisirDate(string message)
{
    cout << message << endl;

    int jour = -1;
    cout << "Veuillez saisir le jour: ";
    cin >> jour;
    while(std::cin.fail() || (jour > 31) || (jour < 1)) 
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Jour invalide. Re-essayer:\n";
        cin >> jour;
    }   

    int mois = -1;
    cout << "Veuillez saisir le mois: ";
    cin >> mois;
    while(std::cin.fail() || (mois < 1) || (mois > 12)) 
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Mois invalide. Re-essayer:\n";
        cin >> mois;
    }


    int annee = -1;
    cout << "Veuillez saisir l'annee: ";
    cin >> annee;
    while(std::cin.fail() || (annee < 1)) 
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Annee invalide. Re-essayer:\n";
        cin >> annee;
    }

    Date d = Date(jour,mois,annee);
    return d;
}

int Saisie::saisirInt(string message)
{
    cout << message << endl;
    int nombre;
    cin >> nombre;
    while(std::cin.fail()) 
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Saisie invalide. Re-essayer:\n";
        cin >> nombre;
    }

    return nombre;
}


Coordonnee Saisie::saisirCoordonnees(string message)
{
    cout << message << endl;
}
