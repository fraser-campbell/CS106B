/*
 * File: ReverseStr.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: Reverses a string using both iteractive and recursive strategies
 * 
 */

#include <iostream>
#include <string>
 using namespace std;

// Consider recursing on the subsets of strings
string ImplReverseStrRecur(string reverse, string nonreverse){
	//Base case when nonreverse is length == 0
	if(nonreverse.length()==0){
		return reverse;
	}
	else{
		reverse.push_back(nonreverse.back()); //Add char to reverse
		// cout << reverse << endl;
		nonreverse.pop_back(); //Remove char from nonreverse
		// cout << nonreverse << endl;
		return ImplReverseStrRecur(reverse, nonreverse);
	}
}

// This is a wrapper function
string ReverseStrRecur(string input){
	return ImplReverseStrRecur("", input);
}

string ImplReverseStrItr(string reverse, string nonreverse){
	for(int i=nonreverse.length(); i>0; i--){
		reverse.push_back(nonreverse[i-1]);
	}
	return reverse;
}

// This is a wrapper function
string ReverseStrItr(string input){
	return ImplReverseStrItr("", input);
}


int main(){
	string Input;
	cout << "Input String: " << endl;
	cin >> Input;
	cout << ReverseStrRecur(Input) << endl;
	cout << ReverseStrItr(Input) << endl;
	return 0;
}