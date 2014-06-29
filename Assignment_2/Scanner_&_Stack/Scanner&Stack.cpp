/*
 * File: Scanner_&_Stack.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: [TODO: enter section leader here] 
 * NB: the html it checks is of the wrong form
 * 
 */

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

bool IsCorrectlyNested(string htmlStr){
	string input;
	stringstream mystream; //string stream is used so I can read in inputs as tokens one at a time
	stack<string> stck;
	mystream << htmlStr;

	while(getline(mystream, input, '>')){
		if(input[0]!='<') input = input.substr(input.find("<")); //Removes the text which is not in html tags
		if (input[input.size()-1]=='/'){ //This if statement puts all open html elements into a stack
			stck.push(input+'>');
		}
		else{ //This else statement compares the input with the last element in the stack
			int position = stck.top().size(); //Store the size of the string in order to facilitate parsing & comparison below
			if((input + '>') != stck.top().erase(position-2,1)){
				cout << "failed here" << endl;
				return false;
			}
			else{
				stck.pop();
				cout <<"Got here" << endl;
			}
		}
	}
	return true;
}



int main(){

if(IsCorrectlyNested("<html/><b/>Something in here<b><html><p/><p>")) cout<<"Well nested!"<< endl;
else cout<<"poorly nested" << endl;

// string input;
// stack<string> stck;
// stringstream test("<html/><b/><b><html><p/><p>");

// //"<html><b> something </html></b>"
// while(getline(test, input, '>')){
// 	stck.push(input+'>');
// }

// while(stck.empty()==false){
// 	cout << stck.top() << endl;
// 	stck.pop();
// }

	return 0;
}

