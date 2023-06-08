#include <iostream>
#include <sstream>
using namespace std;
#include <algorithm>

#include "Saisie.h"

void clear_cin()
{
    cin.clear();
    cin.seekg(0, ios::end);

    if (!cin.fail())
    {
        cin.ignore(numeric_limits<streamsize>::max());
    }
    else
    {
        cin.clear();
    }
}

bool isNb(string & text)
{
    text.erase(std::remove(text.begin(), text.end(), '\n'), text.cend());
    string numbers = "0123456789";
    for(long unsigned int i = 0 ; i < text.size() ; i++)
    {
        if(numbers.find(text[i]) == std::string::npos)
        {
            return false;
        }
    }
    return true;
}

int Saisie::saisirInt(const string &message)
{
    int nombre;
    string input;
    cout << message << endl;
    clear_cin();
    cin >> input;
    while (!isNb(input))
    {
        cout << "Saisie invalide. Re-essayez:\n";
        clear_cin();
        cin >> input;
    }
    clear_cin();
    nombre = stoi(input);
    return nombre;
}

Date Saisie::saisirDate(string message)
{
    cout << message << endl;
    int jour = -1;
    while((jour > 31) || (jour < 1)) 
    {
        jour = saisirInt("Veuillez saisir le jour: ");
    }  
    int mois = -1;
    while((mois < 1) || (mois > 12)) 
    {
        mois = saisirInt("Veuillez saisir le mois: ");
    } 
    int annee = -1;
    while((annee < 1)) 
    {
       annee = saisirInt("Veuillez saisir l'annee: ");
    }
    Date d = Date(jour,mois,annee);
    return d;
}

string Saisie::saisirString(string message)
{
    cout << message << endl;
    string value;
    cin >> value;
    cin.clear();
    return value;
}

Coordonnees Saisie::saisirCoordonnees(string message)
{
    cout << message << endl;
    float longitude;
    cout << "Veuillez saisir la longitude: ";
    cin >> longitude;
    while (std::cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Saisie invalide. Re-essayer:\n";
        cin >> longitude;
    }

    float latitude;
    cout << "Veuillez saisir la latitude: ";
    cin >> latitude;
    while (std::cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Saisie invalide. Re-essayer:\n";
        cin >> latitude;
    }

    Coordonnees c = Coordonnees(latitude, longitude);
    return c;
}
