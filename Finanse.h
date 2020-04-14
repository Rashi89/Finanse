#include <iostream>

#include "UsersMenager.h"
#include "IncomeMenager.h"

using namespace std;

class Finanse
{
    UsersMenager usersMenager;
    IncomeMenager *incomeMenager;

public:
    Finanse()
    {
        incomeMenager=NULL;
    }
    ~Finanse()
    {
        delete incomeMenager;
        incomeMenager=NULL;
    }
    void rejestracjaUzytkownika();
    void wyswietlWszystkichUzytkownikow();
    void logowanieUzytownika();
    void wylogowanieZalogowanegoUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodajItem();
};
