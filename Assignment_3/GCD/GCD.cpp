/*
 * File: GCD.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: Recursive function to calculate the greatest common denominator of
 *			Two non negative integers
 * 
 */

#include <iostream>
#include <string>
 using namespace std;


int gcd(int a, int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}

int main(){

	cout << gcd(8,4) << endl;
	cout << gcd(27,18) << endl;


	return 0;
}