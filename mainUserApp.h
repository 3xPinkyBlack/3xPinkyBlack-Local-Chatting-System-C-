#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "userMessage.h"
using namespace std;

void viewProfile(char*);
void findFriends();
void updateProfile(char*);

void mainUserApp(char* firstName, char *lastName, char *userName) {
    int choice;
    char sendChatDB[100] = "Z:\\chatFiles\\";
    strcat(sendChatDB, userName);
    strcat(sendChatDB, ".SQL");
        do {
            userMenuBar(firstName, lastName);
            choice = enterChoice();

            switch(choice) {
                case 1:
                    userMenuBar(firstName, lastName); 
                    viewProfile(userName); 
                    break;
                case 2:
                    userMenuBar(firstName, lastName); 
                    sendMessage(sendChatDB, userName, firstName, lastName); 
                    break;
                case 3:
                    userMenuBar(firstName, lastName);
                    viewMessage(sendChatDB, userName, firstName, lastName); 
                    break;
                case 4:
                    userMenuBar(firstName, lastName);
                    findFriends(); 
                    break;
                case 5:
                    userMenuBar(firstName, lastName);
                    updateProfile(userName); 
                    break;
                case 6:
                    userMenuBar(firstName, lastName);
                    groupMembers(); 
                    break;
                case 7:
                    userMenuBar(firstName, lastName);
                    viewChat();
                    break;
                case 8:
                    choice = 7;
                    break;
                default: 
                    choice = 0; 
                    break;
            }

        } while(choice != 7);
}

void viewProfile(char *userName) {
    userInfo UI;
    fstream userDB;
    userDB.open("Z:\\chatFiles\\UserDatabase.SQL", ios::in | ios::binary);
        while(userDB.read((char *)&UI, sizeof(UI))) {
             if(strcmp(userName, UI.userName) == 0) {
                 cout<<"Your Name is ----->> "<<UI.firstName<<" "<<UI.lastName<<endl;
                 cout<<"Your UserName is ->> "<<UI.userName<<endl;
                 cout<<"Your Password is ->> "<<UI.userPass<<endl;
                 cout<<"Your Email is ---->> "<<UI.emailAddr<<endl;
                 cout<<"Your Gender is --->> "<<UI.gender<<endl;
                 cout<<"Your Phone is ---->> "<<UI.phoneNum<<endl;
                 break;
             }
        }
        
    userDB.close();
    getch();
}


void findFriends() {
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

void updateProfile(char *userName) {
    userInfo UI;
    fstream userDB, userDB1;
    userDB.open("Z:\\chatFiles\\UserDatabase.SQL", ios::in | ios::binary);
    userDB1.open("Z:\\chatFiles\\UserDatabase1.SQL", ios::out | ios::binary | ios::app);
       
        while(userDB.read((char *)&UI, sizeof(UI))) {
            if(strcmp(userName, UI.userName) == 0) {
                cout<<"\t\t\tEnter New Password --->> ";
                cin.ignore();
                cin.get(UI.userPass,10);

                cout<<"\t\t\tEnter Your First Name ->> ";
                cin.ignore();
                cin.get(UI.firstName,10);

                cout<<"\t\t\tEnter Your Last Name -->> ";
                cin.ignore();
                cin.get(UI.lastName,10);

                cout<<"\t\t\tEnter Your Phone Number ->> ";
                cin.ignore();
                cin.get(UI.phoneNum,14);

                cout<<"\t\t\tEnter Your Email Address -> ";
                cin.ignore();
                cin.get(UI.emailAddr,20);
            }

            userDB1.write((char *)&UI, sizeof(UI));
        }

        userDB.close();
        userDB1.close();

        remove("Z:\\chatFiles\\UserDatabase.SQL");
        rename("Z:\\chatFiles\\UserDatabase1.SQL","Z:\\chatFiles\\UserDatabase.SQL");

        cout<<"\n\n\t\tYour Information is Sucessfully Updated, Please Keep Your Information Safely\n";
    getch();
}

