#include "Test.h"

bool Test::testerCapteurDansZone(){
    string directoryPath = "./dataset/dataset-test/";
    Donnees donnees(directoryPath);
    Service service(donnees);

    //1 degré = 119 km

    Coordonnees pointCentral(0,0);
    float rayon = 119.0;
    Date dateDebut (1,1,2019);
    Date dateFin (3,1,2019);

    Mesure mesureTemoin(10,10,10,10);
    Mesure mesureTest = service.voirStatsZone(pointCentral, rayon, dateDebut, dateFin);

    
    cout << "\nTest 1 : voir les statistiques sur une zone" << endl;
    cout << "Resultats attendus : " << mesureTemoin << endl;
    cout << "Resultats obtenus : " << mesureTest << endl ;

    bool testValide = mesureTemoin.concentrationNO2 == mesureTest.concentrationNO2 ? true : false;
    string reponse = testValide == true ? "valide" : "invalide";
    cout << "Le test 1 est donc " << reponse << endl << endl; 

    //Test unitaire 2 sur la méthode dans le cas ou aucun capteur n'est présent dans la zone
    //Doit retourner une valeur de -1 -1 -1 -1 pour la mesure
    pointCentral = Coordonnees(100,100);
    mesureTemoin = Mesure(-2,-2,-2,-2);
    mesureTest = service.voirStatsZone(pointCentral, rayon, dateDebut, dateFin);

    bool test2Valide = mesureTemoin.concentrationNO2 == mesureTest.concentrationNO2 ? true : false;
    reponse = testValide == true ? "valide" : "invalide";    
    
    cout << "Test 2 : Voir les statistiques d'une zone sans capteurs" << endl;
    cout << "Resultats attendus : " << mesureTemoin << endl;
    cout << "Resultats obtenus : " << mesureTest << endl;
    cout << "Le test 2 est donc " << reponse << endl << endl; 

    //Test unitaire 3 sur la méthode dans le cas ou aucun capteur n'a de mesures sur la période
    //Doit retourner une valeur de -1 -1 -1 -1 pour la mesure
    pointCentral = Coordonnees(0,0);
    mesureTemoin = Mesure(-1,-1,-1,-1);
    dateDebut = Date(1,1,2022);
    dateFin = Date(1,1,2023);
    mesureTest = service.voirStatsZone(pointCentral, rayon, dateDebut, dateFin);

    bool test3Valide = mesureTemoin.concentrationNO2 == mesureTest.concentrationNO2 ? true : false;
    reponse = testValide == true ? "valide" : "invalide";    
    
    cout << "Test 3 : Voir les statistiques d'une zone alors qu'aucune mesure n'a été réalisée" << endl;
    cout << "Resultats attendus : " << mesureTemoin << endl;
    cout << "Resultats obtenus : " << mesureTest << endl;
    cout << "Le test 3 est donc " << reponse << endl << endl; 

    return testValide && test2Valide && test3Valide;
}

bool Test::testerMesurerEfficacitePurificateur(){

    string directoryPath = "./dataset/dataset-test/";
    Donnees donnees(directoryPath);
    Service service(donnees);

    pair<Mesure, Mesure> resultatTest = service.consulterImpactPurificateur("Cleaner0", 120);
    Mesure mesureAvantTemoin(100,100,100,100);
    Mesure mesureApresTemoin(0,0,0,0);

    cout << "\nTest 1 : Consulter l'impact d'un purificateur d'air" << endl;
    cout << "Resultats attendus : " << mesureAvantTemoin << endl;
    cout << "et : " << mesureApresTemoin << endl;
    cout << "Resultats obtenus : " << resultatTest.first << endl;
    cout << "et : " << resultatTest.second << endl;

    bool testValide = (mesureApresTemoin.concentrationNO2 == resultatTest.second.concentrationNO2)
                    && (mesureAvantTemoin.concentrationNO2 == resultatTest.first.concentrationNO2)
                     ? true : false;
    string reponse = testValide ? "valide" : "invalide";              
    cout << "Le test 1 est donc " << reponse << endl << endl; 
    return testValide;
}