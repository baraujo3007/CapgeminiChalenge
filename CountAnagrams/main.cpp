
#include <string>
#include <iostream>
#include "funclib.h"

using namespace std;




int main(){

    //anagrams word;
    string input;
    int n=0;

    cout << "Type a string: ";
    cin >> input;

    input = toLower(input); //Asure that all letter are low caser
    
    n = countAnagrams(input);

    cout << "The string has " << n << " anagrams \n";

    return 0;
}
