#include <iostream>
#include <vector>

#include "Income.h"
#include "IncomeMenager.h"
#include "Markup.h"

void IncomeMenager::dodajItem() {
    Income income;

    cout << " >>> DODAWANIE NOWEGO ITEMU <<<" << endl << endl;
    income=podajNowyItem();
    incomes.push_back(income);
    dopiszItemDoPliku(income);

    //plikiZUsers.dopiszUzytkownikaDoPliku(user);
}

Income IncomeMenager::podajNowyItem() {
    Income income;

    income.ustawIncomeID(pobierzIdNowegoItemu());
    income.ustawUserID(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    int amount;
    string data,item;

        cout << "Podaj date: ";
        cin.sync();
        data=wczytajLinie();
        income.ustawDate(data);
        cout << "Podaj nazwe produktu: ";
        cin.sync();
        item=wczytajLinie();
        income.ustawItem(item);
        cout << "Podaj kwote: ";
        cin.sync();
        cin>>amount;
        income.ustawAmount(amount);

    return income;
}

int IncomeMenager::pobierzIdNowegoItemu() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().pobierzIncomeID() + 1;
}

void IncomeMenager::dopiszItemDoPliku(Income income)
{
    CMarkup xml;
    if(xml.Load( "Income.xml" )==false) {
        xml.AddElem( "INCOMES" );
        xml.IntoElem();
        xml.AddElem( "INCOME" );
        xml.IntoElem();
        xml.AddElem( "INCOMEID", income.pobierzIncomeID() );
        xml.AddElem( "USERID", income.pobierzUserID() );
        xml.AddElem( "DATE", income.pobierzDate() );
        xml.AddElem( "ITEM", income.pobierzItem() );
        xml.AddElem( "AMOUNT", income.pobierzAmount() );

        xml.OutOfElem();
        xml.Save( "Income.xml" );
    } else {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "INCOME" );
        xml.IntoElem();
        xml.AddElem( "INCOMEID", income.pobierzIncomeID() );
        xml.AddElem( "USERID", income.pobierzUserID() );
        xml.AddElem( "DATE", income.pobierzDate() );
        xml.AddElem( "ITEM", income.pobierzItem() );
        xml.AddElem( "AMOUNT", income.pobierzAmount() );
        xml.OutOfElem();
        xml.Save( "Income.xml" );
    }
}

vector <Income> IncomeMenager::wczytajItemyZPliku(int idZalogowanegoUzytkownika)
{
    vector <Income> incomes;
    Income income;

    CMarkup xml;
    xml.Load( "Income.xml" );
    xml.FindElem("INCOMES"); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("INCOME") ) {
        xml.IntoElem();
        xml.FindElem( "USERID" );
        int nUserID =atoi( MCD_2PCSZ(xml.GetData()) );
        if(nUserID==idZalogowanegoUzytkownika){
        income.ustawUserID(nUserID);
        xml.FindElem( "INCOMEID" );
        int nIncomeID =atoi( MCD_2PCSZ(xml.GetData()) );
        income.ustawIncomeID(nIncomeID);
        xml.FindElem("DATE");
        MCD_STR strDate = xml.GetData();
        income.ustawDate(strDate);
        xml.FindElem("ITEM");
        MCD_STR strItem = xml.GetData();
        income.ustawItem(strItem);
        xml.FindElem( "AMOUNT" );
        int nAmount =atoi( MCD_2PCSZ(xml.GetData()) );
        income.ustawAmount(nAmount);
        xml.OutOfElem();
        incomes.push_back(income);
        }
    }
}

string IncomeMenager::wczytajLinie() {
    string wejscie;
    getline(cin, wejscie);
    //cin.ignore();
    //cin.get();
    return wejscie;
}
