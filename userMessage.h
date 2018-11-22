#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;

struct Message {    
    char userName[20];
    char userMess[1000];
    char from[20];
    char toFullName[40];
    char fromFullName[40];
};

void sendMessage(char *sendChatDB, char *from, char* firstName, char *lastName) {
    Message UM;
    userInfo UI;
    fstream chatDB, chatDB1, userDB;
    chatDB.open(sendChatDB, ios::out | ios::app | ios::binary);
    userDB.open("Z:\\chatFiles\\UserDatabase.SQL", ios::binary | ios::in);

    char recDir[100] = "Z:\\chatFiles\\";
    int check = 0;

    do {
        cout<<"\n\t\tEnter The Receiver UserName ->> ";
        cin.ignore();
        cin.get(UM.userName, 15);
            while(userDB.read((char *)&UI, sizeof(UI))) {
                if((strcmp(UM.userName, UI.userName) == 0) && (strcmp(UM.userName, from) != 0)) {
                    check = 1;
                    strcpy(UM.toFullName, UI.firstName);
                    strcat(UM.toFullName, " ");
                    strcat(UM.toFullName, UI.lastName);
                    
                    strcpy(UM.from, from);
                    strcat(recDir, UI.userName);
                    strcat(recDir, ".SQL");
                    chatDB1.open(recDir,ios::out | ios::app | ios::binary);
                }
            }
    } while(check == 0);
    
    strcpy(UM.fromFullName, firstName);
    strcat(UM.fromFullName, " ");
    strcat(UM.fromFullName, lastName);
    
    cout<<UM.toFullName<<" "<<UM.fromFullName<<endl;

    cout<<"\n\tEnter The Message You Want to Send To "<<UM.toFullName<<" "<<UM.fromFullName<<endl<<"\t";
    cin.ignore();
    cin.get(UM.userMess, 900);
    
    chatDB.write((char *)&UM, sizeof(UM));
    chatDB1.write((char *)&UM, sizeof(UM));

    userDB.close();
    chatDB1.close();
    chatDB.close();
    getch();
}

void viewMessage(char *sendChatDB, char *from, char* firstName, char *lastName) {
    Message UM;
    userInfo UI;
    fstream chatDB;
    chatDB.open(sendChatDB, ios::in | ios::binary);

    char sendReceive[30] = "";

        while(chatDB.read((char *)&UM, sizeof(UM))) {
            strcpy(sendReceive,  "");
            if(strcmp(UM.from, from) == 0) {
                strcpy(sendReceive,  "To: ");
                strcat(sendReceive, UM.toFullName);
            } else {
                strcpy(sendReceive, "From: ");
                strcat(sendReceive, UM.fromFullName);
            }
                cout<<"\n---------------------------------------------------------------------\n";
                cout<<sendReceive<<"\n";
                cout<<"############################\n\t";
                cout<<UM.userMess;
                cout<<"\n#####################################################################\n";
        }
    chatDB.close();
    getch();
}

void viewChat() {
    getch();
}

