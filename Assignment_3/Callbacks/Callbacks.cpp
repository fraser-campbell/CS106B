/*
 * File: Callbacks.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: [TODO: enter section leader here] 
 * 
 */

 // #include <set>
#include <string>
#include <iostream>

 using namespace std;

 struct entryT {
 	string firstName;
 	string lastName;
 	string phoneNumber;
 };

 void to_lower_case(string &change);

 int CmpEntry(entryT a, entryT b)
 {
 	to_lower_case(a.lastName);
 	to_lower_case(b.lastName);
	if (a.lastName == b.lastName){
		to_lower_case(a.firstName);
 		to_lower_case(b.firstName);
		if(a.firstName == b.firstName){
			if(a.phoneNumber == b.phoneNumber){
				return 0;
			}
			else if (a.phoneNumber < b.phoneNumber) return -1;
			else return 1;
		}
		else if (a.firstName < b.firstName) return -1;
		else return 1;
	}
	else if (a.lastName < b.lastName) return -1;
	else return 1;
 }

 void to_lower_case(string &change){
 	for(string::iterator itr=change.begin(); itr<change.end(); ++itr){
 		*itr = tolower(*itr);
 		// cout << tolower(*itr) << endl;
 	}
 }


// typedef set<entryT> entries; // Cannot create set constructors at this stage syntax too complicated
// Need ot introduce comparison callback functions to show how to analyse comparisons within sets

 int main(){

 	// Below is checking examples of the defined function working dor different structures
	entryT fraser = {
		"Fraser", "Campbell", "07968581796"
	};

	entryT sabine = {
		"Sabine", "Crevoisier", "07939918903"
	};

	entryT campbell = {
		"Fraser", "Cambpbell", "07968581796"
	};

	entryT campbel = {
		"fraser", "Cambpbell", "07968581796"
	};

	int result  = CmpEntry(fraser, sabine);
	cout << result << endl; //1st check
	cout << CmpEntry(fraser, campbell) << endl; //Check strings compared lexicographic order
	cout << CmpEntry(campbel, campbell) << endl; //Check strings compared lexicographic order

	to_lower_case(sabine.lastName);
	cout << sabine.lastName << endl;


 	return 0;
 }