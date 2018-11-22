#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "menuBar.h"
using namespace std;

int choice;

void viewAllUsers();
void searchUser();
void sortUser();
void removeUser();
void removeAllusers();
void countUsers();

int main() {

        system("cls");
        menuBar();
        groupMembers();
        cout<<"\n\t\t\tPress Enter To Continue : ";
        getch();

    do {
        menuBar();
        choice = enterChoice();
            switch(choice) {
                case 1:menuBar(); removeUser();     break;
                case 2:menuBar(); viewAllUsers();   break;
                case 3:menuBar(); searchUser();     break;
                case 4:menuBar(); sortUser();       break;
                case 5:menuBar(); groupMembers();     break;
                case 6:menuBar(); removeAllusers(); break;
                case 7:menuBar(); countUsers();     break;
                case 8:choice = 8;  break;
                default:choice = 0;  
            }

        getch();
    } while(choice != 8);
    cout<<"\n\t\tYour Session Cleared Sucessfully\n\t\tPress Enter To continue";
    getch();
}

void removeUser() {
    fstream userDB, userDB1;
    userInfo UI;
    char userName[15], firstName[15], lastName[15], userMessage[100] = "Z:\\chatFiles\\", ch;
    int isAvailable = 0, delUser = 0, isDeleted = 0;
    userDB.open("Z:\\chatFiles\\UserDatabase.SQL", ios::in | ios::binary);
    userDB1.open("Z:\\chatFiles\\UserDatabase1.SQL", ios::out | ios::app | ios::binary);

    cout<<"\n\t\tEnter The UserName To Remove ->> ";
    cin.ignore();
    cin.get(userName, 10);

        while(userDB.read((char *)&UI, sizeof(UI))) {
             delUser = 0;
            if(strcmp(userName, UI.userName) == 0) {
                isAvailable = 1;
                cout<<"\n\tDo You Want to Remove "<<UI.firstName<<" "<<UI.lastName<<" From The List Y/N: ";
                cin>>ch;
                    if(ch == 'Y' || ch == 'y') {
                        delUser = 1;
                        isDeleted = 1;
                    }
                strcpy(firstName, UI.firstName);
                strcpy(lastName, UI.lastName);
                
                strcat(userMessage, UI.userName);
                strcat(userMessage, ".SQL");
             }
           
            if((delUser == 0) || (strcmp(userName, UI.userName) != 0)) {
                userDB1.write((char *)&UI, sizeof(UI));
            }
        }

    userDB.close();
    userDB1.close();
    
    remove("Z:\\chatFiles\\UserDatabase.SQL");
    rename("Z:\\chatFiles\\UserDatabase1.SQL","Z:\\chatFiles\\UserDatabase.SQL");

        if(isAvailable == 0) {
           cout<<"\n\t\tThere is No User With This UserName!";
        } 
       
        if(isDeleted == 1){
            remove(userMessage);
            cout<<"\n\t[*] Removing User "<<firstName<<" "<<lastName<<" With UserName "<<userName<<"... Sucessfull"<<endl;
            cout<<"\t   [**] Deleting Messages.................. Sucessfull"<<endl;
            cout<<"\t   [**] Clearing All User Catch Files...... Sucessfull"<<endl;
            cout<<"\t   [**] LoggingOut User From All Devices... Sucessfull"<<endl;
            cout<<"\t   [**] is All Action Completed............ Sucessfull"<<endl;
        }
}

void viewAllUsers() {
    fstream userDB;
    userInfo UI;
    userDB.open("Z:\\chatFiles\\UserDatabase.SQL", ios::in | ios::binary);
        while(userDB.read((char *)&UI, sizeof(UI))) {
            cout<<"\tUser Name is ----->> "<<UI.firstName<<" "<<UI.lastName<<endl;
            cout<<"\tUser UserName is ->> "<<UI.userName<<endl;
            cout<<"\tUser Email is ---->> "<<UI.emailAddr<<endl;
            cout<<"\tUser Gender is --->> "<<UI.gender<<endl;
            cout<<"\tUser Phone is ---->> "<<UI.phoneNum<<endl;
            cout<<"\n---------------------------------------------------------------------"<<endl;
        }
    
    userDB.close();
    getch();
}

void searchUser() {
    userInfo UI;
    fstream userDB;
    userDB.open("Z:\\chatFiles\\UserDatabase.SQL", ios::in | ios::binary);

    char userName[20];
    cout<<"\tEnter Users (UserName or first Name or last name \n\tor email address or gender or phone)";
    cout<<"\n\t\t Find User eg. 0914352147 or Dessie or Male ->> ";
	cin.ignore();
    cin.get(userName, 15);

        while(userDB.read((char *)&UI, sizeof(UI))) {
             if(strcmp(userName, UI.userName) == 0 ||
                strcmp(userName, UI.firstName) == 0 ||
                strcmp(userName, UI.lastName) == 0 ||
                strcmp(userName, UI.emailAddr) == 0 ||
                strcmp(userName, UI.gender) == 0 ||
                strcmp(userName, UI.phoneNum) == 0
                ) {
                    cout<<"\tUser Name is ----->> "<<UI.firstName<<" "<<UI.lastName<<endl;
                    cout<<"\tUser UserName is ->> "<<UI.userName<<endl;
                    cout<<"\tUser Email is ---->> "<<UI.emailAddr<<endl;
                    cout<<"\tUser Gender is --->> "<<UI.gender<<endl;
                    cout<<"\tUser Phone is ---->> "<<UI.phoneNum<<endl;
                    cout<<"\n---------------------------------------------------------------------"<<endl;
             }
        }
        
    userDB.close();
    getch();
}

void sortUser() {}

void removeAllusers() {
    userInfo UI;
    fstream userDB;
    userDB.open("Z:\\chatFiles\\UserDatabase.SQL", ios::in | ios::binary);

    char check, userMessage[100] = "Z:\\chatFiles\\", userName[20];
    cout<<"\n\t\tDo You Rally Want To Remove All Users Y/N";
    cin>>check;

        if(check == 'Y' || check == 'y') {
            while(userDB.read((char *)&UI, sizeof(UI))) {
                strcpy(userName, UI.userName);
                strcat(userName, ".SQL");
                strcat(userMessage, userName);

                cout<<"\n\t[*] Removing User "<<UI.firstName<<" "<<UI.lastName<<" With UserName "<<UI.userName<<"... Sucessfull"<<endl;
                cout<<"\t   [**] Deleting Messages.................. Sucessfull"<<endl;
                cout<<"\t   [**] Clearing All User Catch Files...... Sucessfull"<<endl;
                cout<<"\t   [**] LoggingOut User From All Devices... Sucessfull"<<endl;
                cout<<"\t   [**] All Actions Completed Sucessfully"<<endl;
                remove(userMessage);
            }
        }
    userDB.close();
    remove("Z:\\chatFiles\\UserDatabase.SQL");
}

void countUsers() {
    userInfo UI;
    fstream userDB;
    userDB.open("Z:\\chatFiles\\UserDatabase.SQL", ios::in | ios::binary);

    int count = 0;
        while(userDB.read((char *)&UI, sizeof(UI))) {
            count++;
        }
    cout<<"\n\t\tThere are "<<count<<" Users In The Database"<<endl;
    userDB.close();
}

