/*
 * File: cannonballs.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: This program reads the number of cannonballs given the number of layers
 * 
 */
 #include <iostream>
 #include <cmath>
 using namespace std;

int Cannonball(int height){
	if(height == 1) return 1;
	else {
		return pow(height,2) + Cannonball(height-1);
	}
}

 int main(){

 	cout << "Input the number of layers of cannonballs: " << endl;
 	int number;
 	cin >> number;
 	cout << "There are " << Cannonball(number) << " cannonballs" << endl;
 	
 	return 0;
 }