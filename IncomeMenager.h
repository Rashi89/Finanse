#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H
#include <iostream>
#include <vector>

#include "Income.h"
#include "IncomeMenager.h"

using namespace std;

class IncomeMenager
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Income> incomes;

    Income podajNowyItem();
    int pobierzIdNowegoItemu();

public:
    IncomeMenager(int idZalogowanegoUzytkownika): ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        incomes = wczytajItemyZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };
    void dodajItem();
    void dopiszItemDoPliku(Income income);
    vector <Income> wczytajItemyZPliku(int idZalogowanegoUzytkownika);

     string wczytajLinie();

};

#endif
