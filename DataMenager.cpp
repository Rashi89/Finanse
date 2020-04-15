#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <windows.h>
#include <winbase.h>

#include <windows.h>
#include "DataMenager.h"
#include "IncomeMenager.h"
#include "data.h"
#include "Markup.h"

bool DataMenager::podajDate(string wpisanaData) {
    vector <Data> daty;
    Data data;
    //string wpisanaData;
    int id,rok,miesiac,dzien;
    //cout<<"Podaj date: ";
    //cin>> wpisanaData;
    rok=zamienDateNaRok(wpisanaData);
    miesiac=zamienDateNaMiesiac(wpisanaData);
    dzien=zamienDateNaDzien(wpisanaData);
    //cout<<rok<<" "<<miesiac<<" "<<dzien<<endl;
    if(czyDataJestPoprawna(rok, miesiac, dzien)==true) {
        data.ustawID(pobierzIDNowejDaty());
        data.ustawRok(rok);
        data.ustawMiesiac(miesiac);
        data.ustawDzien(dzien);
        data.ustawDataZMyslnikami(wpisanaData);
        data.ustawDataBezMyslnikow(konwersjaStringNaInt(zamienDateNaNapisBezMyslnikow(wpisanaData)));
        daty.push_back(data);
    } else
        cout<<"Bledna data!"<<endl;
}

Data DataMenager::pobierzDzisiejszaDate()
{
    vector <Data> daty;
    Data data;
    SYSTEMTIME st;
    GetSystemTime(&st);
        data.ustawID(pobierzIDNowejDaty());
        data.ustawRok(st.wYear);
        data.ustawMiesiac(st.wMonth);
        data.ustawDzien(st.wDay);
        string wpisanaData;
        wpisanaData+=konwersjaIntNaString(st.wYear);
        wpisanaData+="-";
        if(st.wMonth<10)
        {
            wpisanaData+="0";
            wpisanaData+=konwersjaIntNaString(st.wMonth);
            wpisanaData+="-";
        }
        else{
            wpisanaData+=konwersjaIntNaString(st.wMonth);
            wpisanaData+="-";
        }
        if(st.wDay<10)
        {
            wpisanaData+="0";
            wpisanaData+=konwersjaIntNaString(st.wDay);
        }
        else{
           wpisanaData+=konwersjaIntNaString(st.wDay);
        }

        data.ustawDataZMyslnikami(wpisanaData);
        data.ustawDataBezMyslnikow(konwersjaStringNaInt(zamienDateNaNapisBezMyslnikow(wpisanaData)));
        daty.push_back(data);
        return data;
}

int DataMenager::pobierzIDNowejDaty() {
    vector <Data> daty;
    if (daty.empty() == true)
        return 1;
    else
        return daty.back().pobierzID() + 1;
}

bool DataMenager::czyRokJestPrzestepny(int rok) {
    if(rok%4==0&&rok%100!=0) {
        return true;
    } else if(rok%400==0) {
        return true;
    } else {
        return false;
    }
}
bool DataMenager::czyDataJestPoprawna(int rok, int miesiac, int dzien) {
    if(miesiac>12)
        return false;
    if(miesiac==1||miesiac==3||miesiac==5||miesiac==7||miesiac==8||miesiac==10||miesiac==12) {
        if(dzien<=31&&dzien>=1) {
            return true;
        } else
            return false;
    } else if(miesiac==4||miesiac==6||miesiac==9||miesiac==11) {
        if(dzien<=30&&dzien>=1) {
            return true;
        } else
            return false;
    } else if(miesiac==2) {
        if(czyRokJestPrzestepny(rok)==true) {
            if(dzien<=29&&dzien>=1) {
                return true;
            } else
                return false;
        } else {
            if(dzien<=28&&dzien>=1) {
                return true;
            } else
                return false;
        }
    }
}

int DataMenager::zamienDateNaRok(string wpisanaData) {
    int rok;
    string pojedynczaDana = "";
    int numerPojedynczejDanej = 1;
    for(int pozycjaZnaku=0; pozycjaZnaku<wpisanaData.length(); pozycjaZnaku++) {
        if (wpisanaData[pozycjaZnaku] != '-') {
            pojedynczaDana += wpisanaData[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanej) {
            case 1:
                rok=(atoi(pojedynczaDana.c_str()));
                break;
            }
            pojedynczaDana = "";
            numerPojedynczejDanej++;
        }
    }
    return rok;
}
int DataMenager::zamienDateNaMiesiac(string wpisanaData) {
    int miesiac;
    string pojedynczaDana = "";
    int numerPojedynczejDanej = 1;
    for(int pozycjaZnaku=0; pozycjaZnaku<wpisanaData.length(); pozycjaZnaku++) {
        if (wpisanaData[pozycjaZnaku] != '-') {
            pojedynczaDana += wpisanaData[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanej) {
            case 2:
                miesiac=(atoi(pojedynczaDana.c_str()));
                break;
            }
            pojedynczaDana = "";
            numerPojedynczejDanej++;
        }
    }
    return miesiac;
}
int DataMenager::zamienDateNaDzien(string wpisanaData) {
    int dzien,liczba;
    string pojedynczaDana = "";
    int numerPojedynczejDanej = 1;
    for(int pozycjaZnaku=wpisanaData.length()-1; pozycjaZnaku>0; pozycjaZnaku--) {
        if (wpisanaData[pozycjaZnaku] != '-') {
            pojedynczaDana += wpisanaData[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanej) {
            case 1:
                liczba=(atoi(pojedynczaDana.c_str()));
                if(liczba%10==0) {
                    dzien=liczba/10;
                } else
                    dzien=liczba%10*10+(liczba-liczba%10)/10;
                break;
            }
            pojedynczaDana = "";
            numerPojedynczejDanej++;
        }
    }
    return dzien;
}

string DataMenager::zamienDateNaNapisBezMyslnikow(string wpisanaData) {
    string dataBezMyslnikow="";

    int liczbaMyslinkow=0;
    for(int pozycjaZnaku=0; pozycjaZnaku<wpisanaData.length(); pozycjaZnaku++) {
        if(wpisanaData[pozycjaZnaku]=='-') {
            ;
        } else {
            dataBezMyslnikow+=wpisanaData[pozycjaZnaku];
        }
    }
    return dataBezMyslnikow;
}

string DataMenager::dzisiejszaData() {
    //vector <Data> daty;
    Data data;
    data=pobierzDzisiejszaDate();
    string dataZMyslnikami="";
    dataZMyslnikami=data.pobierzDataZMyslnikami();

    return dataZMyslnikami;

    //vector <Data> :: iterator itr = daty.end()-1;
    //pobierzDzisiejszaDateJakoString(*itr);
    //cout <<pobierzDzisiejszaDateJakoString(*itr)<<endl;
    //return pobierzDzisiejszaDateJakoString(*itr);

}
string DataMenager::pobierzDzisiejszaDateJakoString(Data data)
{
    string dataZMyslnikami="";
    dataZMyslnikami=data.pobierzDataZMyslnikami();

    return dataZMyslnikami;
}

vector <Data> DataMenager::wczytajDaty(int idZalogowanegoUzytkownika)
{
    vector <Data> daty;
    Data data;

    int id,rok,miesiac,dzien;

    CMarkup xml;
    xml.Load( "Income.xml" );
    xml.FindElem("INCOMES"); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("INCOME") ) {
        xml.IntoElem();
        xml.FindElem( "USERID" );
        int nUserID =atoi( MCD_2PCSZ(xml.GetData()) );
        //cout<<"id uzytkownika: "<<nUserID<<endl;
        if(nUserID==idZalogowanegoUzytkownika){
        xml.FindElem( "INCOMEID" );
        int nIncomeID =atoi( MCD_2PCSZ(xml.GetData()) );
        //data.ustawIncomeID(nIncomeID);
        xml.FindElem("DATE");
        MCD_STR strDate = xml.GetData();
        rok=zamienDateNaRok(strDate);
        miesiac=zamienDateNaMiesiac(strDate);
        dzien=zamienDateNaDzien(strDate);
        data.ustawID(nIncomeID);
        data.ustawRok(rok);
        data.ustawMiesiac(miesiac);
        data.ustawDzien(dzien);
        data.ustawDataZMyslnikami(strDate);
        data.ustawDataBezMyslnikow(konwersjaStringNaInt(zamienDateNaNapisBezMyslnikow(strDate)));
        xml.OutOfElem();
        daty.push_back(data);
        //incomes.push_back(income);
        }
        else xml.OutOfElem();
    }
    return daty;
}





int DataMenager::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;
    return liczbaInt;
}

string DataMenager::konwersjaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
void DataMenager::sortowanie(vector <Data> &daty)
{
    sort(daty.begin(),daty.end());
}
