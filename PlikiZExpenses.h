#ifndef PLIKIZEXPENSES_H
#define PLIKIZEXPENSES_H
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
//
#include "Expense.h"
#include "Markup.h"
#include "data.h"
#include "DataMenager.h"
#include "AdditionalMethods.h"

//#include "Expense.h"
//#include "data.h"
//#include "DataMenager.h"
//#include "MetodyPomocnicze.h"
//#include "Markup.h"

using namespace std;

class PlikiZExpenses
{
    const string NAME_FILE_EXPENSES;
    DataMenager dataMenager;
public:
    PlikiZExpenses(string nameFileExpenses): NAME_FILE_EXPENSES(nameFileExpenses){};
    vector <Expense> loadExpensesFromFile(int idZalogowanegoUzytkownika);
    vector <Data> wczytajDatyZPliku(int idZalogowanegoUzytkownika);
    void appendExpenseToFile(Expense expense);
};
#endif
