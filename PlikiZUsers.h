#ifndef PLIKIZUSERS_H
#define PLIKIZUSERS_H
#include <iostream>
#include <vector>
//
#include "User.h"
#include "Markup.h"


using namespace std;

class PlikiZUsers {

    const string NAME_FILE_USERS;

public:
    PlikiZUsers(string nameFileUsers): NAME_FILE_USERS(nameFileUsers){};
    vector <User> loadUsersFromFile();
    void appendUserToFile(User user);
    void saveAllUsersToFile(vector <User> &users);

};
#endif
