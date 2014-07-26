/*
 * File: step_program.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: [TODO: enter section leader here] 
 * 
 */

 // #include <set>
#include <string>
#include <iostream>
 using namespace std;

int CountWays_impl(int numStairs, int numTaken, int &counter);

int CountWays(int numStairs){
	int counter = 0;
	int numTaken = 0;
	return counter = CountWays_impl(numStairs, numTaken, counter);
}

int CountWays_impl(int numStairs, int numTaken, int &counter){
		//Base case number of steps is equal to zero, num of stairs is equal to zero
	if(numStairs == numTaken){ counter+=1; }
	else if(numStairs > numTaken){
		CountWays_impl(numStairs, numTaken+2, counter);
		CountWays_impl(numStairs, numTaken+1, counter);
	}
	return counter;
}

int main(){

	//Should be 8
	cout << CountWays(5) << endl;
	//Should be 5
	cout << CountWays(4) << endl;
	//Should be 3
	cout << CountWays(3) << endl;

	return 0;
}