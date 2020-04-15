#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H
#include <iostream>
#include <vector>

#include "Income.h"
#include "IncomeMenager.h"
#include "PlikiZIncomes.h"
#include "DataMenager.h"
#include "Markup.h"

using namespace std;

class IncomeMenager :public DataMenager
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Income> incomes;
    //vector <Data> daty;
    PlikiZIncomes plikiZIncomes;
    DataMenager dataMenager;

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
