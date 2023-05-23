#include <iostream>
#include <string>
using namespace std;

#include "../utile/Coordonnees.h"
#include "../utile/Date.h"

class Purificateur{
    public:

        Purificateur();
        
        string id;
        Coordonnees coordonnees;
        Date startTime;
        Date stopTime;
        string entrepriseId;


        virtual ~Purificateur();
};