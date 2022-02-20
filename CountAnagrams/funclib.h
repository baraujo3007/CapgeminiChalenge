//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
#include <string>
#include <iostream>
#include<bits/stdc++.h>
#include<cctype>

//#include "funclib.hpp"


using namespace std;

string toLower(string word) {
    transform(word.begin(), word.end(), word.begin(),
       [](unsigned char c){ return tolower(c); }
    );
    return word;
}


bool areAnagrams(string str1, string str2){

     if (is_permutation(str1.begin(), str1.end(), str2.begin())){
                    //cout<< "Are anagrams: '" << str1 << "'     and      '" << str2 << "' \n";
                    return true;
    } else {
        return false;
    }

}

int countAnagrams(string word){

    string str1, str2;
    int i, j, k, n, anagrams=0;

    n=word.size();

      for (i=0; i<n; i++){
        for (j=i+1; j<n; j++){
            for (k=0; k<n; k++){

                str1 += word[i+k];
                str2 += word[j+k];


                if (areAnagrams(str1, str2)){
                    anagrams++;
                }
            }

            str1 = "";
            str2 = "";

            }
    }

    return anagrams;
}