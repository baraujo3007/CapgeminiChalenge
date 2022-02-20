#include "func.hpp"
#include <string>
#include <iostream>
#include <stdbool.h>
#include<ctype.h>

using namespace std;

// return 0 if the minimum number of characters were fullfiled,
//if not, return how many are missing
int rules::toSix(string word){ 

    int s = word.size();

    if (s>=6){
        //cout<< " At least 6 characters - OK \n";
        return 0;
    } else {
        //cout<< " At least 6 characters - X \n";
        return 6-s;
    }
}

//return true if finds a lower case in any position
bool rules::hasLowerCase(string word){

    int i, thereIs = 0, s=word.size();

    for (i = 0; i < s; i++ ){

        if (islower(word[i])){
                thereIs = 1;
                break;
        }
    }

    if (thereIs){
        //cout << "Lower Case - OK \n";
        return true;
    } else {
        //cout << "Lower Case - X \n";
        return false;
    }
}

//return true if finds a upper case in any position
bool rules::hasUpperCase(string word){

    int i, thereIs = 0, s=word.size();

    for (i = 0; i < s; i++ ){

        if (isupper(word[i])){
                thereIs = 1;
                break;
        }
    }

    if (thereIs){
        //cout << "Upper Case - OK \n";
        return true;
    } else {
        //cout << "Upper Case - X \n";
        return false;
    }

}

//return true if finds a digit in any position
bool rules::hasNumber(string word){

    int i, thereIs = 0, s=word.size();

    for (i = 0; i < s; i++ ){

        if (isdigit(word[i])){
                thereIs = 1;
                break;
        }
    }

    if (thereIs){
        //cout << "Digit - OK \n";
        return true;
    } else {
        //cout << "Digit - X \n";
        return false;
    }

}

//return true if finds a special character in any position
//Uses table ASCII
bool rules::hasSpecialChar(string word){

    int i, thereIs = 0, s=word.size();

    for (i = 0; i < s; i++ ){

        if (   (    (word[i] >= 33) && (word[i] <= 45) &&   (word[i]!= 34) && (word[i]!=39) && (word[i]!=44)   )   || (word[i]==64)    ) {
                thereIs = 1;
                break;
        }
    }

    if (thereIs){
        //cout << "Special Char - OK \n";
        return true;
    } else {
        //cout << "Special Char - X \n";
        return false;
    }
    
}