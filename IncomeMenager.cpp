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
    plikiZIncomes.dopiszItemDoPliku(income);

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

void IncomeMenager::wyswietlWszystkieItemy()
{
    if (!incomes.empty()) {
        cout << "             >>>PRODUKTY<<<" << endl;
        cout << "-----------------------------------------------" << endl;
        //cout<<incomes.size()<<endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            wyswietlItem(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak produktow." << endl << endl;
    }
}

void IncomeMenager::wyswietlItem(Income income)
{
    cout<<"ID uzytkownika: "<< income.pobierzUserID()<<endl;
    cout<<"ID itemu: "<< income.pobierzIncomeID()<<endl;
    cout<<"Data: "<< income.pobierzDate()<<endl;
    cout<<"Nazwa itemu: "<< income.pobierzItem()<<endl;
    cout<<"Koszt: "<< income.pobierzAmount()<<endl;
}


string IncomeMenager::wczytajLinie() {
    string wejscie;
    getline(cin, wejscie);
    //cin.ignore();
    //cin.get();
    return wejscie;
}
