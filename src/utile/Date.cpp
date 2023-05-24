#include"Date.h"
#include <iostream>
Date::Date()
:jour(1), mois(1), annee(2000)
{}

bool Date::operator<(const Date& autreDate) const {
    bool vrai;
    if(this->annee != autreDate.annee){
        return this->annee < (autreDate.annee) ? true : false;
    }
    if(this->mois != autreDate.mois){
        return this->mois < (autreDate.mois) ? true : false;
    }
    if(this->jour != autreDate.jour){
        return this->jour < (autreDate.jour) ? true : false;
    }
    return false;
}

bool Date::operator==(const Date& autreDate) const{
    return (this->annee == autreDate.annee) && (this->mois == autreDate.mois) && (this->jour == autreDate.jour);
}

Date::Date(string dateTimeString)
{
    size_t pos = dateTimeString.find(" "); 
    string dateString = dateTimeString.substr(0,pos);

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

ostream& operator <<(ostream & os, const Date date)
{
    os << date.jour << "/" << date.mois << "/" << date.annee ;
    return os;
}

Date::~Date(){}