#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H
#include <iostream>
#include <vector>

#include "Income.h"
#include "IncomeMenager.h"
#include "PlikiZIncomes.h"
#include "Markup.h"

using namespace std;

class IncomeMenager
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Income> incomes;
    PlikiZIncomes plikiZIncomes;

    Income podajNowyItem();
    int pobierzIdNowegoItemu();
    void wyswietlItem(Income income);

public:
    IncomeMenager(int idZalogowanegoUzytkownika): ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        incomes = plikiZIncomes.wczytajItemyZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };
    void dodajItem();
    void wyswietlWszystkieItemy();


    string wczytajLinie();

};

#endif
