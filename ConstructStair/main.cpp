//main file for ConstructStair

#include <string>
#include <iostream>

using namespace std;

void constructor(int n){

    int i, j;

    for (i=1; i<=n; i++){ 
        for (j=0; j < (n-i); j++){   //For each line, prints the right number of spaces
            cout << " ";
        }
        for (j=(n-i); j<n; j++){    //For eache line, prints the right number of *
            cout << "*";
        }
        cout << "\n";
    }

}

int main(){

    int step;
    
    cout << "Enter the number of steps: \n";
    cin >> step;

    constructor(step);

    return 0;
}
