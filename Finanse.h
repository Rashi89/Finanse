#include <iostream>

#include "UsersMenager.h"
#include "IncomeMenager.h"
//#include "DataMenager.h"

using namespace std;

class Finanse
{
    UsersMenager usersMenager;
    IncomeMenager *incomeMenager;
    //DataMenager *dataMenager;

public:
    Finanse()
    {
        incomeMenager=NULL;
        //dataMenager=NULL;
    }
    ~Finanse()
    {
        delete incomeMenager;
        incomeMenager=NULL;
        //delete dataMenager;
        //dataMenager=NULL;

    }
    void rejestracjaUzytkownika();
    void wyswietlWszystkichUzytkownikow();
    void logowanieUzytownika();
    void wylogowanieZalogowanegoUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodajItem();
    void wyswietlWszystkieItemy();
};
