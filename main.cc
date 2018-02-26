#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <cstdio>
#include "HugeInteger.h"

int main(){
    HugeInteger intgr;
	HugeInteger intgr22("12abc"); //testing the one string arg constructor
	HugeInteger intgr2(intgr22); //testing copy contructor
	HugeInteger intgr3("123");

	HugeInteger intgr1001("1001");
	HugeInteger intgr1002("1002");
	HugeInteger intgr2003("2003");
	
	//testing the + operator
	HugeInteger intgr4(intgr1001 + intgr1002);
	if ( intgr4 == intgr2003)
		cout << "the + operator works" << endl;

	//testing the == operator
	if (intgr22 == intgr2)
		cout << "== operator works" << endl;

	//testing the > operator
	if (intgr3 > intgr2)
		cout << "> operator works" << endl;

	//testing the isZero()
	if (intgr.isZero())
		cout << "isZero() works for the no argument constructor" << endl;

	//testing the toString() and the one argument string constructor
	cout << "12 = " << intgr2.toString() << endl;


    return 0;
}