#ifndef PLIKIZINCOMES_H
#define PLIKIINCOMES_H
#include <iostream>
#include <vector>
//
#include "Income.h"
#include "Markup.h"
#include "data.h"
#include "DataMenager.h"

using namespace std;

class PlikiZIncomes
{
public:
    vector <Income> wczytajItemyZPliku(int idZalogowanegoUzytkownika);
    vector <Data> wczytajDatyZPliku(int idZalogowanegoUzytkownika);
    void dopiszItemDoPliku(Income income);
};
#endif
