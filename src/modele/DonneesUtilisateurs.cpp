/*************************************************************************
                           DonneesUtilisateurs  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <DonneesUtilisateurs> (fichier DonneesUtilisateurs.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "./DonneesUtilisateurs.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type DonneesUtilisateurs::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void DonneesUtilisateurs::AjouterUtilisateurDansListe(const Utilisateur u)

{
    string email = u.email;
//pour ne pas ajouter des hit cible/referer qui ne sont pas dans le créneau horaire demandé
    //int compare = cible.compare("nepasutiliser");
    
        
        listeUtilisateurs::iterator it = listeU.find(email);
        //pour l'ajout d'une paire dont la cible est déjà connue
        if(it== listeU.end())
        {
           
            
            listeU.insert(make_pair(email, u));
            it = listeU.find(email);
            
        }
        //ajout d'une paire dont la cible n'est pas connue
        



}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
DonneesUtilisateurs::DonneesUtilisateurs ( const DonneesUtilisateurs & unDonneesUtilisateurs )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <DonneesUtilisateurs>" << endl;
#endif
} //----- Fin de DonneesUtilisateurs (constructeur de copie)


DonneesUtilisateurs::DonneesUtilisateurs ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DonneesUtilisateurs>" << endl;
#endif
} //----- Fin de DonneesUtilisateurs


DonneesUtilisateurs::~DonneesUtilisateurs ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DonneesUtilisateurs>" << endl;
#endif
} //----- Fin de ~DonneesUtilisateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
