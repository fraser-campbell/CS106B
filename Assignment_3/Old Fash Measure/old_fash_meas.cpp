/*
 * File: old_fash_meas.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: Recursive backtracking function to calculate whether weights sufficient
 * to measure a given weight
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool IsMeasureable(int target, vector<int> weights){
	//Need to find base conditions
	//1. weights.size() == 0 all weights discarded - backtrack
	if(weights.size()==0) return false;
	cout << "length " << weights.size() << endl;
	cout << "target " << target << endl;
	//2. target == weights (therefore true)
	int sum_of_elems = 0;
	for(vector<int>::iterator j=weights.begin(); j!=weights.end(); ++j) sum_of_elems += *j;
   	cout << "sum_of_elems " << sum_of_elems << endl;
	if(target == sum_of_elems) return true;
	//Below loops through the different positions and considers adding or disregarding these weights
	// for(vector<int>::iterator i=weights.begin(); i!=weights.end(); ++i){
		int new_value = weights.front();
		// int new_value = *i;
		// vector<int> new_vec; //Need to create a new temporary vector
		// new_vec = weights; //Make this vector equal to the previous vector
		weights.erase(find(weights.begin(), weights.end(), new_value)); //Erase the relevant element from this vector
		
		//Check whether the new weights condition with weight added to the other side is solveable
		if(IsMeasureable(target + new_value, weights)) {		
			return true;
		}
		//Check whether the new weights condition with weight removed is solveable
		if(IsMeasureable(target, weights)) {	
			return true;
		}
	// }
	//None of the other arrangements returned true so false
	return false;
}

//---------------------------------SECOND IMPLEMENTATION--------------------------------------------------------

bool Measureable2(int target, vector<int> &weights, int count){
	if(target==0) return true;

	if(count>=weights.size()) return false;

	return Measureable2(target + weights[count], weights, count+1) || Measureable2(target - weights[count], weights, count+1) || Measureable2(target, weights, count+1);
}

//Wrapper for IsMeasureable2 - this adds the count argument used to loop through the returns
bool IsMeasureable2(int target, vector<int> &weights){
	return Measureable2(target, weights, 0);
}

int main(){

vector<int> sampleWeights;
sampleWeights.push_back(1);
sampleWeights.push_back(2);
sampleWeights.push_back(3);
sampleWeights.push_back(4);

cout << IsMeasureable(5, sampleWeights) << endl;
cout << IsMeasureable(10, sampleWeights) << endl;
cout << IsMeasureable(11, sampleWeights) << endl;

cout << IsMeasureable2(5, sampleWeights) << endl;
cout << IsMeasureable2(10, sampleWeights) << endl;
cout << IsMeasureable2(11, sampleWeights) << endl;


 	return 0;
}