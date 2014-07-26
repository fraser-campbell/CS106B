/*
 * File: RecursivePuzzle.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: Reverses a string using both iteractive and recursive strategies
 * 
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_square(vector<int> square){
	cout << "[ ";
	for(vector<int>::iterator itr=square.begin(); itr!=square.end(); ++itr){
		cout << *itr << " ,";
	}
	cout << "]"<< endl;
}

bool SolvableImpl(int start, vector<int> & squares2);

bool Solvable(int start, vector<int> & squares){
	vector<int> squares2 = squares;
	return SolvableImpl(start, squares2);
}

//Strategy id to mark a square zero if we have already been on it as only the last square should be zero
bool SolvableImpl(int start, vector<int> & squares2){
	if(start == (squares2.size()-1)) return true; // reached the index of the final square
	else{
		cout << "position: " << start << endl;
		print_square(squares2);
		//Move to the right
		if(start+squares2[start]<squares2.size() and (squares2[start+squares2[start]] != 0 or start+squares2[start]==(squares2.size()-1))) {
			vector<int> squares_new = squares2;
			int position = start + squares_new[start];
			cout << "position_new " << position << endl;
			squares_new[start] = 0;  //Mark current square as 0 as moving from here
			if(SolvableImpl(position, squares_new)){
				return true;
			}
		}
		if(start-squares2[start] >= 0 and squares2[start-squares2[start]] != 0) {
			vector<int> squares_new = squares2;
			int position = start - squares_new[start];
			squares_new[start] = 0;  //Mark current square as 0 as moving from here
			if(SolvableImpl(position, squares_new)){
				return true;
			}
		}
	}
	return false; //could not find a solution
}

// Consider recursing on the subsets of strings
int main(){
	int start = 0;
	vector<int> rect;
	rect.push_back(3);
	rect.push_back(1);
	rect.push_back(2);
	rect.push_back(3);
	rect.push_back(0);
	cout << Solvable(start, rect) << endl;

	vector<int> squares;
	squares.push_back(3);
	squares.push_back(6);
	squares.push_back(4);
	squares.push_back(1);
	squares.push_back(3);
	squares.push_back(4);
	squares.push_back(2);
	squares.push_back(5);
	squares.push_back(3);
	squares.push_back(0);
	cout << Solvable(start, squares) << endl;
	return 0;
}




