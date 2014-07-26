/*
* File: warmups.cpp
* -----------------
* Name: Fraser Campbell
* Descrip: The code creates a function to put integers into binary form
*
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

// bool CanMakeSum(vector<int> & nums, int targetSum);
bool MakeSum(vector<int> soFar, vector<int> rest, int targetSum);

// ------------------------In-Binary Problem------------------------------------------------------------
void print_vector(vector<int> &storage_vec){
	//NB: Have to reverse iterate as the vector stores the result bacwards
	for(vector<int>::reverse_iterator ritr=storage_vec.rbegin(); ritr!=storage_vec.rend(); ++ritr){
		cout << *ritr << " ";	
	}
		cout << endl;
}
void PrintInBinary(int num, vector<int> &storage_vec){
	//Base case is when your num becomes 0
	if(num == 0) print_vector(storage_vec);
	//
	else{
		storage_vec.push_back(num % 2); 
		PrintInBinary(num/2, storage_vec);
	}
}

// ------------------------Sub-Set Problem--------------------------------------------------------------

int sum_vector(vector<int> v){
	int sum=0;
	for(vector<int>::iterator itr=v.begin(); itr!=v.end(); ++itr){
		sum+=*itr;
	}
	return sum;
}

bool CanMakeSum(vector<int> nums, int targetSum){
	vector<int> soFar;
	vector<int> rest;
	rest = nums;
	return MakeSum(soFar, rest, targetSum);
}

bool MakeSum(vector<int> soFar, vector<int> rest, int targetSum){
	//Base case
	if(rest.empty()){
		if(sum_vector(soFar)==targetSum) return true;
	} 
	//Remainder of the recursion
	else{
		int last_element = rest.back();
		rest.pop_back();
		soFar.push_back(last_element);
		if(MakeSum(soFar, rest, targetSum)){
			return true;
		}
		soFar.pop_back();
		if(MakeSum(soFar, rest, targetSum)){
			return true;
		}
	}
	return false; //This returns false if not equal to targetSum or all sets exhausted
}


int main(){

	vector<int> storage_vec;
	PrintInBinary(12, storage_vec);
	storage_vec.clear();
	PrintInBinary(13, storage_vec);
	storage_vec.clear();
	PrintInBinary(14, storage_vec);
	storage_vec.clear();
	PrintInBinary(15, storage_vec);
	storage_vec.clear();
	PrintInBinary(16, storage_vec);
	storage_vec.clear();
 	PrintInBinary(17, storage_vec);
 	storage_vec.clear();


 	vector<int> vec_of_num;
 	vec_of_num.push_back(1);
 	vec_of_num.push_back(2);
 	vec_of_num.push_back(3);
 	vec_of_num.push_back(4);
 	vec_of_num.push_back(5);

 	cout << CanMakeSum(vec_of_num, 10) << endl;
 	cout << CanMakeSum(vec_of_num, 16) << endl;

	return 0;
}



