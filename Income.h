#ifndef INCOME_H
#define INCOME_H
#include <iostream>

using namespace std;

class Income {
    int incomeID;
    int userID;
    string date;
    string item;
    int amount;

public:

    Income(int incomeID=0, int userID=0, string date="", string item="",int amount=0) {
        this->incomeID = incomeID;
        this->userID=userID;
        this->date=date;
        this->item=item;
        this->amount=amount;
    }

    //setery
    void ustawIncomeID(int newIncomeID);
    void ustawUserID(int newUserID);
    void ustawDate(string newDate);
    void ustawItem(string newItem);
    void ustawAmount(int newAmount);
    //getery
    int pobierzIncomeID();
    int pobierzUserID();
    string pobierzDate();
    string pobierzItem();
    int pobierzAmount();

};




#endif
