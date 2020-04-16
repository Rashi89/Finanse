#include <iostream>
#include <vector>
#include "Markup.h"
#include "Finanse.h"
#include "DataMenager.h"
#include "IncomeMenager.h"

using namespace std;

int main() {
    Finanse finanse;
    //finanse.rejestracjaUzytkownika();
    //finanse.wyswietlWszystkichUzytkownikow();
    finanse.logowanieUzytownika();
    //finanse.wyswietlWszystkieItemy();
    //finanse.wylogowanieZalogowanegoUzytkownika();
    //finanse.zmianaHaslaZalogowanegoUzytkownika();
    //finanse.dodajItem();
    //finanse.sortowanie();
    //finanse.wyswietlWszystkieItemy();
    //finanse.wyswietlItemyZTegoMiesiaca();
    //finanse.wyswietlItemyZPoprzedniegoMiesiaca();
    //finanse.obliczWydatkiZObecnegoMiesiaca();
    //finanse.obliczWydatkiZPoprzedniegoMiesiaca();
    //DataMenager dataMenager;
    //dataMenager.wczytajDatyZPliku();
    //dataMenager.pobierzDzisiejszaDate();
    //dataMenager.wyswietlDaty();
    //dataMenager.dzisiejszaData();
    //finanse.sortowanie();
    //finanse.wyswietlWszystkieDaty();
    finanse.wyznaczZakresBilansu();



    return 0;
}
