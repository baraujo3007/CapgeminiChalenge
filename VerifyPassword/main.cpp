#include <string>
#include <iostream>
#include"func.hpp"

using namespace std;


int main(){

    rules password;
    string word;
    int result, testNot, nMiss;

    cout<<"Enter the password: \n";
    cin>>word;

    nMiss = password.toSix(word);

    testNot = !password.hasLowerCase(word) + !password.hasUpperCase(word) + !password.hasNumber(word) + !password.hasSpecialChar(word);


    if ((nMiss == 0) && (testNot==0)){

        cout << "\n  ------------------\n";
        cout << " | STRONG PASSWORD! |\n";
        cout << "  ------------------\n\n";

    } else {

        cout << "\n  ----------------\n";
        cout << " | WEAK PASSWORD! | \n";
        cout << "  ----------------\n\n";

        if (nMiss >= testNot){
            result = nMiss;
        } else {
            result = testNot;
        }
        cout << "Password needs "<< result << " more character(s). \n\n";
    }

return 0;

}
