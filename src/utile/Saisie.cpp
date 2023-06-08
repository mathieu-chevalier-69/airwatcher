#include <iostream>
using namespace std;

#include "Saisie.h"

/*
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
*/


/*
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
*/

int Saisie::saisirInt(const std::string& message) {
        std::cout << message << std::endl;
        std::string input;
        int result;

        while (true) {
            std::getline(std::cin, input);

            try {
                size_t pos;
                result = std::stoi(input, &pos);

                // Vérifier si la saisie contient d'autres caractères après l'entier
                if (pos < input.length()) {
                    std::cout << "Saisie invalide. Veuillez entrer un entier valide." << std::endl;
                    continue;
                }

                // La saisie est valide
                break;
            } catch (const std::invalid_argument&) {
                std::cout << "Saisie invalide. Veuillez entrer un entier valide." << std::endl;
            } catch (const std::out_of_range&) {
                std::cout << "Saisie invalide. L'entier est hors de la plage valide." << std::endl;
            }
        }

        return result;
    }


Date Saisie::saisirDate(string message)
{
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
    while(std::cin.fail()) 
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Saisie invalide. Re-essayer:\n";
        cin >> longitude;
    }


    float latitude;
    cout << "Veuillez saisir la latitude: ";
    cin >> latitude;
    while(std::cin.fail()) 
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Saisie invalide. Re-essayer:\n";
        cin >> latitude;
    }

    Coordonnees c = Coordonnees(latitude, longitude);
    return c;
}
