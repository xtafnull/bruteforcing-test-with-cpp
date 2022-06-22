#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include "btalgo.h"

using namespace std;

void display_menu();

void options_menu(string &, short int &, vector<char>);

void run_brute_force(string, vector<char>);

int main(){

    //program variables
    short int menu_option = 0;

    string passwd = "admin";

    short int passwd_length = 5;

    vector<char> passwd_characters {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!', '@', '#', '&', '(', ')', '[', '{', '}', ']', ':', ';', ',', '?', '/', '*'}; 

    while(menu_option != 3){

        display_menu();
        cin >> menu_option;

        if(menu_option == 1){
            run_brute_force(passwd, passwd_characters);
        }

        else if(menu_option == 2){
            options_menu(passwd, passwd_length, passwd_characters);
        }

        else if(menu_option == 3){}

        else{
            cout << "There is no such option...\nTry again!";
            getchar();getchar();
        }

    }

}

void display_menu(){
    system("clear");
    cout << "1 - RUN\n2 - OPTIONS\n3 - EXIT\n:";
}

void options_menu(string &passwd, short int &passwd_length, vector<char> passwd_characters){
    short int options_menu_choice = 0;
    while(options_menu_choice != 4){
        system("clear");
        cout << "Current password :" << passwd << "\nCurrent password length: " << passwd_length;
        cout << "\n1 - Reroll Password\n2 - Custom Password\n3 - Change password length\n4 - Exit Options Menu\n:";
        cin >> options_menu_choice;
        if(options_menu_choice==1){
            passwd = "";
            int r;
            for(int i = 0;i < passwd_length;i++){
                r = rand() % passwd_characters.size(); 
                passwd = passwd + passwd_characters[r];
            }
        }
        else if(options_menu_choice==2){
            system("clear");
            cout << "Input the new password: ";
            cin >> passwd;
        }
        else if(options_menu_choice==3){
            system("clear");
            cout << "Input new password length: ";
            cin >> passwd_length;
        }
    }
}

void run_brute_force(string passwd, vector<char> passwd_characters){
    system("clear");
    cout << "Password to crack: " << passwd;
    cout << "\nCracking...";
    auto start = std::chrono::high_resolution_clock::now();
    brute_force_algorithm(passwd, passwd_characters);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    auto duration_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    cout << "\nThe operation took: " << duration_microseconds.count() << " (microseconds)";
    cout << "\nThe operation took: " << duration_milliseconds.count() << " (milliseconds)";
    getchar();getchar();
}