#include <iostream>
#include <conio.h>
using namespace std;

int menuBarChoice;

struct userInfo {
   char userName[15];
   char userPass[15];
   char firstName[15];
   char lastName[15];
   char gender[15];
   char emailAddr[30];
   char phoneNum[15];
};

void menuBar() {
    system("cls");
    cout<<"\t\t-----------------------------------------------------\n";
    cout<<"\n\t\t| Wellcome To KIoT Local Chatting System Admin Panel |\n\n";
    cout<<"\t\t-----------------------------------------------------\n\n";
    cout<<"\t\t[1] Remove User | [2] View All Users | [3] Search User | [4] Sort User\n";
    cout<<"\t[5] To View Group Members | [6] Remove All Users | [7] Count Number of Users\n";
    cout<<"\t\t\t[8] To Finish Session\n\n";
    cout<<"---------------------------------------------------------------------------------------\n";
}

void groupMembers() {
    string groupList[6][4] = {{"1622/09","Habib Endris","Software Engineering","Eleven"},
                              {"1272/09","Mhret Leweye","Software Engineering","Eleven"},
                              {"1542/09","Molalign Misgie","Software Engineering","Eleven"},
                              {"1308/09","Bekalu Asefa","Software Engineering","Eleven"},
                              {"1319/09","Misganaw Yimenu","Software Engineering","Eleven"},
                              {"1307/09","Tamralech Tilahun","Software Engineering","Eleven"}
                             };
        cout<<"\tID Number\tDeveloper Name\t\tDeveloper Department\tGroup\n";
        cout<<"\t-- ------\t--------- ----\t\t--------- ----------\t-----\n";
        for(int i=0; i<5; i++) {
            cout<<"\t"<<groupList[i][0]<<"\t\t"<<groupList[i][1]<<"\t\t"<<groupList[i][2]<<"\t"<<groupList[i][3]<<endl;
        }
}

int enterChoice() {
    cout<<"\n\t\t\tEnter Your Choice To Get Started :- ";
    cin>>menuBarChoice;

    return menuBarChoice;
}

