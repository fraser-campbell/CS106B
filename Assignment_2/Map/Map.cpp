/*
 * File: Map.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: [TODO: enter section leader here] 
 * 
 */

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <fstream>
using namespace std;

typedef map<char, int> mymap;

void PrintMapVal(mymap &mappy){
	for(mymap::iterator iter=mappy.begin(); iter != mappy.end(); ++iter){
		cout << "Character: " << iter -> first << "  Value: " << iter -> second << endl;
	}
}

char Itrmax(mymap &mappy, int &numOccurrences){
	char store = ' ';
	int temp_int = 0;
	int maxi=0;
	for(mymap::iterator itr = mappy.begin(); itr != mappy.end(); ++itr){
		temp_int = itr -> second;
		if(maxi <= temp_int){
			maxi = temp_int;
			numOccurrences = temp_int;
			store = itr -> first;	
		}
	}
	return store;
}

char MostFrequentCharacter(ifstream &input, int &numOccurrences){
	if(!input.is_open()) cerr << "Couldn't open the file file.txt" << endl;
	mymap mappy;
	string str;
	while(getline(input, str)){
		for(string::iterator itr = str.begin(); itr != str.end(); ++itr){	
			if(mappy.find(*itr) != mappy.end()){
				mappy[*itr] += 1;
			}
			else {
				mappy.insert(make_pair(*itr, 1));
			}
		}
	}

	PrintMapVal(mappy);
	return Itrmax(mappy, numOccurrences);
}

int main(){
char store;
ifstream input("file.txt");
string str = "happy";
int numOccurrences = 0;
store = MostFrequentCharacter(input, numOccurrences);
cout << "Most frequent character: " << store << endl;
	return 0;
}

