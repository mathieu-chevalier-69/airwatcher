#include "Date.h"
#include <iostream>
using namespace std;
Date::Date()
    : jour(1), mois(1), annee(2000)
{
}

Date::Date(string dateTimeString)
{
    size_t pos = dateTimeString.find(" ");
    string dateString = dateTimeString.substr(0, pos);

    string anneeString = dateString.substr(0, dateString.find("-"));
    dateString.erase(dateString.begin(), dateString.begin() + dateString.find("-") + 1);

    string moisString = dateString.substr(0, dateString.find("-"));
    dateString.erase(dateString.begin(), dateString.begin() + dateString.find("-") + 1);

    string jourString = dateString.substr(0, dateString.find("-"));
    dateString.erase(dateString.begin(), dateString.begin() + dateString.find("-") + 1);

    jour = stoi(jourString);
    mois = stoi(moisString);
    annee = stoi(anneeString);
}

bool Date::operator<(const Date &autreDate) const
{
    if (this->annee != autreDate.annee)
    {
        return this->annee < (autreDate.annee) ? true : false;
    }
    if (this->mois != autreDate.mois)
    {
        return this->mois < (autreDate.mois) ? true : false;
    }
    if (this->jour != autreDate.jour)
    {
        return this->jour < (autreDate.jour) ? true : false;
    }
    return false;
}

bool Date::operator==(const Date &autreDate) const
{
    return (this->annee == autreDate.annee) && (this->mois == autreDate.mois) && (this->jour == autreDate.jour);
}

ostream &operator<<(ostream &os, const Date date)
{
    os << date.jour << "/" << date.mois << "/" << date.annee;
    return os;
}

Date Date::operator-(int jours) const
{
    Date resultat = *this;
    resultat.jour -= jours;

    while (resultat.jour <= 0)
    {
        resultat.mois--;
        if (resultat.mois <= 0)
        {
            resultat.annee--;
            resultat.mois = 12;
        }

        int joursDansMois = getJoursDansMois(resultat.mois, resultat.annee);
        resultat.jour += joursDansMois;
    }

    return resultat;
}

int Date::getJoursDansMois(int mois, int annee) const
{
    static const int joursDansMois[] = {
        0,  // Valeur fictive pour le mois 0
        31, // Janvier
        28, // Février (année non bissextile)
        31, // Mars
        30, // Avril
        31, // Mai
        30, // Juin
        31, // Juillet
        31, // Août
        30, // Septembre
        31, // Octobre
        30, // Novembre
        31  // Décembre
    };

    if (mois == 2 && estAnneeBissextile(annee))
        return 29;
    else
        return joursDansMois[mois];
}

bool Date::estAnneeBissextile(int annee) const
{
    if (annee % 4 != 0)
        return false;
    else if (annee % 100 != 0)
        return true;
    else if (annee % 400 != 0)
        return false;
    else
        return true;
}

Date::~Date() {}