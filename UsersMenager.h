#ifndef USERMENAGER_H
#define USERMENAGER_H
#include <iostream>
#include <vector>

#include "User.h"
#include "Markup.h"
#include "PlikiZUsers.h"
#include "AdditionalMethods.h"

using namespace std;

class UsersMenager {

    int idLoggedUser;
    vector <User> users;
    PlikiZUsers plikiZUsers;

    int getIDNewUser();
    User getDetailsNewUser();

public:
    UsersMenager(string nameFileUsers) : plikiZUsers(nameFileUsers) {
        idLoggedUser=0;
        users = plikiZUsers.loadUsersFromFile();
    };
    void registerUser();
    void loginUser();
    void changePasswordLoggedUser();
    void logoutUser();
    bool isUserLoggedIn();
    int loadIDLoggedUser();
    char selectOptionFromUserMenu();
    bool isLoginExist(string login);

};
#endif
