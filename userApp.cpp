#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "menuBar.h"
#include "userMenuBar.h"
#include "mainUserApp.h"
using namespace std;

void login();
void registerUser();
int userNameValidation(char*);
void mainUserApp(char*,char*);

int main() {
    int choice;
    MapAndHideFolder();
    
    do {
        do {
            system("cls");
            cout<<"\t\t-----------------------------------------------------\n";
            cout<<"\n\t\t| Wellcome To KIoT Local Chatting System |\n\n";
            cout<<"\t\t-----------------------------------------------------\n";
            cout<<"\t\t\t[1] To SignIn \t [2] To Register \t [3] To Exit\n";
            cout<<"---------------------------------------------------------------------------------------\n";
            choice = enterChoice();
        } while(choice < 1 || choice > 2);

            switch(choice) {
                case 1:
                    login();
                    break;
                case 2:
                    registerUser();
                    break;
                case 3:
                    choice = 3;
                    break;
                default:
                    login();
            }
    } while(choice != 3);
}

void login() {
    fstream userDB;
    userInfo UI;
    char userName[15], userPass[15], firstName[15], lastName[15];
    int isAvailable = 0;
    userDB.open("Z:\\chatFiles\\UserDatabase.SQL", ios::in | ios::binary);

        system("cls");
        cout<<"\t\t-----------------------------------------------------\n";
        cout<<"\n\t\t| Wellcome To KIoT Local Chatting System Login Page |\n\n";
        cout<<"\t\t-----------------------------------------------------\n";
        cout<<"\n\n\t\tEnter Your Credential Correctly For Sucessfull Login\n\n";
        cout<<"\t\tEnter Your UserName ->> ";
        cin.ignore();
        cin.get(userName,10);
        cout<<"\t\tEnter Your Password ->> ";
        cin.ignore();
        cin.get(userPass, 10);

            while(userDB.read((char *)&UI, sizeof(UI))) {
                if((strcmp(userName, UI.userName) == 0) && (strcmp(userPass, UI.userPass) == 0)) {
                    isAvailable = 1;
                    strcpy(userName, UI.userName);
                    strcpy(firstName, UI.firstName);
                    strcpy(lastName, UI.lastName);
                    break;
                }
            }

    if(isAvailable == 1) {
        mainUserApp(firstName, lastName, userName);
    }
    userDB.close();
}

void registerUser() {
    fstream userDB, chatDB;
    userInfo UI;
    
    char userName[20], dirName[100] = "Z:\\chatFiles\\";
    userDB.open("Z:\\chatFiles\\UserDatabase.SQL", ios::out | ios::binary | ios::app);

    int validate = 1;
    do {
        system("cls");
        cout<<"\t\t------------------------------------------------------------\n";
        cout<<"\n\t\t| Wellcome To KIoT Local Chatting System Registration Page |\n\n";
        cout<<"\t\t------------------------------------------------------------\n";
        cout<<"\n\n\t\tEnter Your Enformation\n\n";
        
            if(validate == 0) {
                cout<<"\t\t\tThis UserName is Not Available\n\n";
            }

            cout<<"\t\t\tEnter New UserName --->> ";
            cin.ignore();
            cin.get(UI.userName,10);
            validate = userNameValidation(UI.userName);
    } while(validate == 0);
        
        cout<<"\t\t\tEnter New Password --->> ";
        cin.ignore();
        cin.get(UI.userPass,10);

        cout<<"\t\t\tEnter Your First Name ->> ";
        cin.ignore();
        cin.get(UI.firstName,10);

        cout<<"\t\t\tEnter Your Last Name -->> ";
        cin.ignore();
        cin.get(UI.lastName,10);

        cout<<"\t\t\tEnter Your Gender ----->> ";
        cin.ignore();
        cin.get(UI.gender,10);

        cout<<"\t\t\tEnter Your Phone Number ->> ";
        cin.ignore();
        cin.get(UI.phoneNum,14);

        cout<<"\t\t\tEnter Your Email Address -> ";
        cin.ignore();
        cin.get(UI.emailAddr,20);
            
            

            userDB.write((char *)&UI, sizeof(UI));

            strcpy(userName, UI.userName);
            strcat(userName, ".SQL");
            strcat(dirName, userName);
            chatDB.open(dirName,ios::out);
            cout<<dirName;

            cout<<"\n\n\t\tYou Are Successfully Registered, Please Keep Your Information Safely\n";
            cout<<"\t\tYour UserName is: "<<UI.userName<<endl;
            cout<<"\t\tYour Password is: "<<UI.userPass;

        userDB.close();
        chatDB.close();
        getch(); 
}

int userNameValidation(char *userName) {
    fstream userDB;
    userInfo UI;
    int isValid = 1;

    userDB.open("Z:\\chatFiles\\UserDatabase.SQL", ios::in | ios::binary);

        while(userDB.read((char *)&UI, sizeof(UI))) {
            if(strcmp(userName, UI.userName) == 0) {
                isValid = 0;
            }
        }
    return isValid;
}
