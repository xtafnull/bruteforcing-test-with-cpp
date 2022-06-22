#include "btalgo.h"
#include <iostream>
#include <fstream>

using namespace std;

void brute_force_algorithm(std::string passwd, std::vector<char> passwd_characters){

    long long int tries_counter = 0;
    string passwd_try;

    ifstream file("rockyou.txt");

    while(getline(file, passwd_try)){
        tries_counter++;
        if(passwd_try == passwd){
            cout << "The password is: " << passwd_try << "\nIt took " << tries_counter << " tries.";
            break;
        }
    }
    if(passwd_try != passwd){
        cout << "Password was not cracked.";
    }
}