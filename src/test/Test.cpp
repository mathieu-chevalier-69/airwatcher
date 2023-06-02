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

    cout << "Test : voir les statistiques sur une zone" << endl;
    cout << "Resultats attendus : " << mesureTemoin << endl;
    cout << "Resultats obtenus : " << mesureTest << endl;
    bool testValide = mesureTemoin.concentrationNO2 == mesureTest.concentrationNO2 ? true : false;
    cout << "Le test est donc " << testValide << endl; 
    return testValide;
}