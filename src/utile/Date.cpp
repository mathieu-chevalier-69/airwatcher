#include"Date.h"

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

Date::~Date(){}