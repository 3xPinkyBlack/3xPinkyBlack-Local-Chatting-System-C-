#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
using namespace std;

void userMenuBar(char *firstName, char *lastName) {
    system("cls");
    cout<<"\t\t-----------------------------------------------------\n";
    cout<<"\n\t\t| [ "<<firstName<<" "<<lastName<<" ] Wellcome To KIoT Local Chatting System |\n\n";
    cout<<"\t\t-----------------------------------------------------\n\n";
    cout<<"\t[1] View Profile | [2] Send Message | [3] View Messages | [4] Find Friends";
    cout<<"\n\t[5] Update Profile | [6] To View Developers | [7] View Chat | [8] To SignOut\n\n";
    cout<<"---------------------------------------------------------------------------------------\n";
}

void MapAndHideFolder() {
    ofstream mapFolder("FolderMapper.bat");
    mapFolder<<"net use Z: \\\\172.16.26.114\\Users\\kiot\\Documents /user:kiot 1 /P:Yes";
    mapFolder.close();

    system("FolderMapper.bat");
    system("cls");
    remove("FolderMapper.bat");
}


