/*
 * File: Mnemonics.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: Recursive function to generate letter combinations associated with a number
 */

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <set>
 using namespace std;

//Observations
//1. Problem is a permutation problem, as it involves finding permutations of letters
//Problem follows the permutation pseudocode

typedef vector<set<char> > container;
typedef map<int, set<char> > phone_map;

phone_map create_telephone_map();
container rest_creater(string str, phone_map tele_map);
void Mnemonics(string so_far, vector<set<char> > rest);


// Wrapper function for Mnemonic
void listMnemonics(string str){ 
	phone_map tele_map;
	container rest; 
	tele_map = create_telephone_map();
	rest = rest_creater(str, tele_map);
	// cout << rest.size() << endl;
	Mnemonics("", rest);
}
 
//Returns stores all the chars against their relevant numbers
phone_map create_telephone_map(){
	//Create a map container
	phone_map tele_map;
	//Create all the letters of the alphabet as a string except Q and Z uppercase
	string str = "";
	int count = 2;
	for(int i=0; i<26; i++){
		char letter = static_cast<char>('A'+ i);
		// cout << static_cast<char>('A'+ i) << endl;
		if(letter!='Q' && letter!='Z') str.push_back(letter);
		if(str.size()%3==0){
			set<char> temp_set;
			for(string::iterator itr=str.begin(); itr!=str.end(); ++itr){ //push into set character by character
				char temp_char = *itr;
				temp_set.insert(temp_char); // push the character into the set
			}
			tele_map.insert(make_pair(count, temp_set));
			temp_set.clear();	
			str.clear();
			count++;
		}
	}
	return tele_map;
}

//Returns an object which only stores the chars we need for our chosen numbers
container rest_creater(string str, phone_map tele_map){
	//Need to iterate through the string
	container rest;
	for(string::iterator itr = str.begin(); itr!=str.end(); ++itr){
		int temp = *itr - '0'; //Convert char to an integer for map lookup
		if(tele_map.find(temp)!=tele_map.end()){ //Checks that the key exists in the map
			rest.push_back(tele_map[temp]); //Push the set into the vector
		}
	}
	return rest;
}

//Recursive Mnemonic function
void Mnemonics(string so_far, vector<set<char> > rest){
	if(rest.empty()) cout << so_far << endl;
	//[base case when all choices have been made i.e. rest.length()==0]

	else{
		set<char> loop_chars = rest.front(); // Take the first element of the vector rest
		// vector<set<char> > loop_position;
		// loop_position = rest.pop_back
		rest.erase(rest.begin()); // Use an iterator to erase the first element

		//We go through the array one element of the char at a time
		for(set<char>::iterator itr=loop_chars.begin(); itr!=loop_chars.end(); ++itr){
			Mnemonics(so_far + *itr, rest); //Get relevant configurations for this loop position
		}
	}
}


 

int main(){
	listMnemonics("723");
	return 0;
}




