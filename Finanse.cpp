#include "Finanse.h"
#include "UsersMenager.h"
#include "IncomeMenager.h"
#include "DataMenager.h"

void Finanse::rejestracjaUzytkownika()
{
    usersMenager.rejestracjaUzytkownika();
}

void Finanse::wyswietlWszystkichUzytkownikow()
{
    usersMenager.wyswietlWszystkichUzytkownikow();
}

void Finanse::logowanieUzytownika()
{
    usersMenager.logowanieUzytkownika();
    if(usersMenager.czyUzytkownikJestZalogowany())
    {
        incomeMenager = new IncomeMenager(usersMenager.pobierzIdZalogowanegoUzytkownika());
        //dataMenager = new DataMenager(usersMenager.pobierzIdZalogowanegoUzytkownika());

    }
}

void Finanse::wylogowanieZalogowanegoUzytkownika()
{
    usersMenager.wylogowanieZalogowanegoUzytkownika();
}

void Finanse::zmianaHaslaZalogowanegoUzytkownika()
{
    usersMenager.zmianaHaslaZalogowanegoUzytkownika();
}

void Finanse::dodajItem()
{
    if(usersMenager.czyUzytkownikJestZalogowany())
    {
        incomeMenager->dodajItem();
    }
    else
    {
        cout<<"Aby dodac item nalezy sie zalogowac!"<<endl;
        system("pause");
    }
}

void Finanse::wyswietlWszystkieItemy()
{
    if(usersMenager.czyUzytkownikJestZalogowany())
    {
        incomeMenager->wyswietlWszystkieItemy();
    }
}
 void Finanse::wyswietlItemyZTegoMiesiaca()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        incomeMenager->wyswietlItemyZBiezacegoMiesiaca();
    }
 }
  void Finanse::wyswietlItemyZPoprzedniegoMiesiaca()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        incomeMenager->wyswietlItemyZPoprzedniegoMiesiaca();
    }
 }

 void Finanse::obliczWydatkiZObecnegoMiesiaca()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        incomeMenager->obliczWydatkiZObecnegoMiesiaca();
    }
 }
 void Finanse::obliczWydatkiZPoprzedniegoMiesiaca()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        incomeMenager->obliczWydatkiZPoprzedniegoMiesiaca();
    }
 }

  void Finanse::wyznaczZakresBilansu()
 {
     if(usersMenager.czyUzytkownikJestZalogowany())
    {
        incomeMenager->wyznaczZakresBilansu();
    }
 }

void Finanse::wyswietlWszystkieDaty()
{
    if(usersMenager.czyUzytkownikJestZalogowany())
    {
        incomeMenager->wyswietlWszystkieDaty();
    }
}
void Finanse::sortowanie()
{
    if(usersMenager.czyUzytkownikJestZalogowany())
    {
        incomeMenager->sortowanie();
    }
}
