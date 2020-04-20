#ifndef PLIKIZINCOMES_H
#define PLIKIINCOMES_H
#include <iostream>
#include <vector>
//
#include "Expense.h"
#include "Markup.h"
#include "data.h"
#include "DataMenager.h"

using namespace std;

class PlikiZIncomes
{
    DataMenager dataMenager;
    int konwersjaStringNaInt(string liczba);
public:
    vector <Expense> wczytajItemyZPliku(int idZalogowanegoUzytkownika);
    vector <Data> wczytajDatyZPliku(int idZalogowanegoUzytkownika);
    void dopiszItemDoPliku(Expense expense);
};
#endif
