#pragma once
#include "AccountList.h"

int main()
{
    AccountList* temp = new AccountList();
    temp->loadUsers();
    temp->changeCurUser("name5");
    temp->loadCurUserInfo();
    temp->changeCurPass("YEUTHAOOOO");
    std::cout << "* Show users:\n";
    temp->printUSERs();
    std::cout << "* Show cur User:\n";
    temp->showCurUser();
    temp->saveUsers();
    temp->saveCurUserInfo();
    delete temp;
}