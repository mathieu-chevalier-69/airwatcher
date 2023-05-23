#include"Capteur.h"

void Capteur::ajouterMesure(const Mesure & mesure, const Date & date){
    mesures.insert(make_pair(date, mesure));
}

Capteur::~Capteur(){
    
}