#ifndef INCOMEMENAGER_H
#define INCOMEMENAGER_H
#include <iostream>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "PlikiZIncomes.h"
#include "DataMenager.h"
#include "Markup.h"
#include "data.h"

using namespace std;

class IncomeMenager //:public DataMenager
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Income> incomes;
    vector <Data> daty;
    PlikiZIncomes plikiZIncomes;
    DataMenager dataMenager;

    Income podajNowyItem();
    int pobierzIdNowegoItemu();
    void wyswietlItem(Income income);
    int konwersjaStringNaInt(string liczba);
    void wyswietlItemZTegoMiesiaca(Income income);
    void wyswietlItemZPoprzedniegoMiesiaca(Income income);
    int pobierzbiezacyMiesiac();
    void sortowanieItemow(vector <Income> &incomes);
    bool czyWpisanaDataJestPoprawna(string data);

public:
    IncomeMenager(int idZalogowanegoUzytkownika): ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        incomes = plikiZIncomes.wczytajItemyZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        daty = dataMenager.wczytajDaty(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };
    void dodajItem();
    void wyswietlWszystkieItemy();
    void wyswietlWszystkieDaty();
    void wyswietlItemyZBiezacegoMiesiaca();
    void wyswietlItemyZPoprzedniegoMiesiaca();
    void wyswietlDate(Data data);
    void sortowanie();
    void obliczWydatkiZObecnegoMiesiaca();
    void obliczWydatkiZPoprzedniegoMiesiaca();
    void wyznaczZakresBilansu();
    void wyswietlItemyZZakresu(int rokDatyPoczatkowej,int miesiacDatyPoczatkowej,int dzienDatyPoczatkowej,int rokDatyKoncowej,int miesiacDatyKoncowej,int dzienDatyKoncowej);


    string wczytajLinie();

};

#endif
