#include <string>
#include <iostream>
#include <stdbool.h>
#include<ctype.h>
#ifndef FUNC_HPP__
#define FUNC_HPP__

using namespace std;

class rules {

	public:

	   int toSix(string word);

	   bool hasLowerCase(string word);

       bool hasUpperCase(string word);

       bool hasNumber(string word);

       bool hasSpecialChar(string word);

	};

	 

	#endif