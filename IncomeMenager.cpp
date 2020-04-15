#include <iostream>
#include <vector>

#include "Income.h"
#include "data.h"
#include "IncomeMenager.h"
#include "DataMenager.h"
#include "Markup.h"

void IncomeMenager::dodajItem() {
    Income income;

    cout << " >>> DODAWANIE NOWEGO ITEMU <<<" << endl << endl;
    income=podajNowyItem();
    incomes.push_back(income);
    plikiZIncomes.dopiszItemDoPliku(income);
}

Income IncomeMenager::podajNowyItem() {
    vector <Data> daty;
    Income income;
    Data data;
    char znak;
    int amount,dataJakoInt;
    string data1,item,dataJakoString;

    income.ustawIncomeID(pobierzIdNowegoItemu());
    income.ustawUserID(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    cout<<"Czy chcesz dodac nowy produkt z dzisiejsza data? <t/n>"<<endl;
    cin>>znak;
    if(znak=='n')
    {
        cout << "Podaj date: ";
        cin.sync();
        data1=wczytajLinie();
        if(dataMenager.podajDate(data1)==true)
        {
            income.ustawIncomeID(pobierzIdNowegoItemu());
            income.ustawUserID(ID_ZALOGOWANEGO_UZYTKOWNIKA);
            income.ustawDate(data1);
            dataJakoString=dataMenager.zamienDateNaNapisBezMyslnikow(data1);
            dataJakoInt=konwersjaStringNaInt(dataJakoString);
            income.ustawDataJakoInt(dataJakoInt);
            cout << "Podaj nazwe produktu: ";
            cin.sync();
            item=wczytajLinie();
            income.ustawItem(item);
            cout << "Podaj kwote: ";
            cin.sync();
            cin>>amount;
            income.ustawAmount(amount);
        }

        else cout<<"Zle dane!"<<endl;
    }
    else if(znak=='t')
    {
        cout<<"Dzisiejsza data: "<<endl;
        data =dataMenager.pobierzDzisiejszaDate();

        data1=data.pobierzDataZMyslnikami();
        cout<<data1<<endl;
        income.ustawDate(data1);
        dataJakoString=dataMenager.zamienDateNaNapisBezMyslnikow(data1);
        dataJakoInt=konwersjaStringNaInt(dataJakoString);
        cout<<dataJakoInt<<endl;
        //income.ustawDataJakoInt(dataJakoInt);
        cout << "Podaj nazwe produktu: ";
        cin.sync();
        item=wczytajLinie();
        income.ustawItem(item);
        cout << "Podaj kwote: ";
        cin.sync();
        cin>>amount;
        income.ustawAmount(amount);
    }
    else
        cout<<"Zly znak"<<endl;

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

void IncomeMenager::wyswietlWszystkieDaty()
{
    if (!daty.empty()) {
        cout << "             >>> DATY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout<<daty.size()<<endl;
        for (vector <Data> :: iterator itr = daty.begin(); itr != daty.end(); itr++) {
            wyswietlDate(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Brak dat." << endl << endl;
    }
}

void IncomeMenager::wyswietlDate(Data data) {
    if(data.pobierzMiesiac()<10&&data.pobierzDzien()<10) {
        cout<<"Nr daty "<<data.pobierzID()<<": "<<data.pobierzRok()<<"-0"<<data.pobierzMiesiac()<<"-0"<<data.pobierzDzien();
        cout<<" data jako napis: "<<data.pobierzDataZMyslnikami()<<" data jako liczba: "<<data.pobierzDateBezMyslnikow()<<endl;
    } else if(data.pobierzMiesiac()<10) {
        cout<<"Nr daty "<<data.pobierzID()<<": "<<data.pobierzRok()<<"-0"<<data.pobierzMiesiac()<<"-"<<data.pobierzDzien();
        cout<<" data jako napis: "<<data.pobierzDataZMyslnikami()<<" data jako liczba: "<<data.pobierzDateBezMyslnikow()<<endl;
    } else if(data.pobierzDzien()<10) {
        cout<<"Nr daty "<<data.pobierzID()<<": "<<data.pobierzRok()<<"-"<<data.pobierzMiesiac()<<"-0"<<data.pobierzDzien();
        cout<<" data jako napis: "<<data.pobierzDataZMyslnikami()<<" data jako liczba: "<<data.pobierzDateBezMyslnikow()<<endl;
    } else{
        cout<<"Nr daty "<<data.pobierzID()<<": "<<data.pobierzRok()<<"-"<<data.pobierzMiesiac()<<"-"<<data.pobierzDzien();
        cout<<" data jako napis: "<<data.pobierzDataZMyslnikami()<<" data jako liczba: "<<data.pobierzDateBezMyslnikow()<<endl;
    }
}

void IncomeMenager::sortowanie()
{
    //vector <Data> daty;
    sortowanieItemow(incomes);
    //dataMenager.sortowanie(daty);
   //sort(daty.begin(),daty.end());
}

void IncomeMenager::sortowanieItemow(vector <Income> &incomes)
{
    sort(incomes.begin(),incomes.end());

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

int IncomeMenager::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;
    return liczbaInt;
}
