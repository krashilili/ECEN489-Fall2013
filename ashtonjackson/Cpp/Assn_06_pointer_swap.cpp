/*
 * Assn_06_pointer_ValueSwap.cpp
 *
 *  Created on: Sep 18, 2013
 *      Author: ashton
 */

#include <iostream>
using namespace std;

void ValueSwap(int *Val1, int *Val2) {
	int a = *Val1; //temporarily store content of val1 in a
	*Val1 = *Val2; //push content of val2 into val1
	*Val2 = a;  //assign content of a (the previous content of val1) to val2
}

int main() {
	int Val1, Val2;
	cout << "Please enter two integers separated by a single space: " << endl;
	cin >> Val1 >> Val2;

	ValueSwap(&Val1, &Val2); //calls the previous function
	cout << "The swapped values are: " << endl;
	cout << Val1 << " " << Val2 << endl;

	return 0;
}

