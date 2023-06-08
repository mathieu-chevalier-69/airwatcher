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
    for(int i = 0 ; i < text.size() ; i++)
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

Date Saisie::saisirDate(const std::string &message)
{
    std::cout << message << std::endl;
    std::string input;
    int jour, mois, annee;

    while (true)
    {
        std::getline(std::cin, input);

        try
        {
            std::istringstream iss(input);
            char delimiter;
            if (iss >> jour >> delimiter >> mois >> delimiter >> annee &&
                delimiter == '/' &&
                jour >= 1 && jour <= 31 &&
                mois >= 1 && mois <= 12 &&
                annee >= 0 && annee <= 9999)
            {
                // La saisie est valide
                break;
            }
            else
            {
                std::cout << "Saisie invalide. Veuillez entrer une date valide au format JJ/MM/YYYY." << std::endl;
            }
        }
        catch (const std::exception &)
        {
            std::cout << "Saisie invalide. Veuillez entrer une date valide au format JJ/MM/YYYY." << std::endl;
        }
    }

    return Date(jour, mois, annee);
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
