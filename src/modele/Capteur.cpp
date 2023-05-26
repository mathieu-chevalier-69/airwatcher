#include"Capteur.h"

void Capteur::ajouterMesure(const Mesure & mesure, const Date & date){
    mesures.insert(make_pair(date, mesure));
}

Capteur::~Capteur(){
    
}

ostream& operator<<(ostream& os, const Capteur& capteur){
    os << capteur.id << ": " << capteur.coordonees << ", Propriétaire : " << capteur.proprietaire;
    return os;
}