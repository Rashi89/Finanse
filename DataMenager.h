#ifndef DATAMENAGER_H
#define DATAMENAGER_H
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#include "data.h"
#include "Income.h"
//#include "IncomeMenager.h"



using namespace std;

class DataMenager
{
    //vector <Data> daty;
    bool czyRokJestPrzestepny(int rok);


    int pobierzIDNowejDaty();

    int konwersjaStringNaInt(string liczba);
    string konwersjaIntNaString(int liczba);
    //string zamienDateNaNapisBezMyslnikow(string wpisanaData);

public:
    DataMenager(){
        //daty = wczytajDaty(int idZalogowanegoUzytkownika);
    }

    vector <Data> wczytajDaty(int idZalogowanegoUzytkownika);
    bool podajDate(string wpisanaData);
    void sortowanie(vector <Data> &daty);
    Data pobierzDzisiejszaDate();
    string dzisiejszaData();
    string pobierzDzisiejszaDateJakoString(Data data);
    string zamienDateNaNapisBezMyslnikow(string wpisanaData);
    int zamienDateNaRok(string wpisanaData);
    int zamienDateNaDzien(string wpisanaData);
    int zamienDateNaMiesiac(string wpisanaData);
    bool czyDataJestPoprawna(int rok, int miesiac, int dzien);





};
#endif
