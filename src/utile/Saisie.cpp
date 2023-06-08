#include <iostream>
#include <sstream>
using namespace std;

#include "Saisie.h"



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


Date Saisie::saisirDate(const std::string& message) {
        std::cout << message << std::endl;
        std::string input;
        int jour, mois, annee;

        while (true) {
            std::getline(std::cin, input);

            try {
                std::istringstream iss(input);
                char delimiter;
                if (iss >> jour >> delimiter >> mois >> delimiter >> annee &&
                    delimiter == '/' &&
                    jour >= 1 && jour <= 31 &&
                    mois >= 1 && mois <= 12 &&
                    annee >= 0 && annee <= 9999) {
                    // La saisie est valide
                    break;
                } else {
                    std::cout << "Saisie invalide. Veuillez entrer une date valide au format JJ/MM/YYYY." << std::endl;
                }
            } catch (const std::exception&) {
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
