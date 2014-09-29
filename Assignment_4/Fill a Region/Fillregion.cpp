/*
 * File: Fillregion.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: Write a function to fill a region in C++
 */

// #include <map>
#include <string>
#include <vector>
#include <iostream>
// #include "grid.h"
// #include <set>
using namespace std;

enum pixelStateT { White, Black };
struct pointT { int row, col; };
typedef vector<vector<pixelStateT> > grid; //This sets the size of the grid to 100*100 pixels


void FillRegion(pointT pt, grid &screen, pixelStateT current){

	if( 0 < pt.row < 9 && screen[pt.row][pt.col] == current){

//First need to check where the pointT pt is
//Then check if any of the adjacent points in that row are the same color and change those
	//Check the positive direction with a for loop
		int positive = pt.col;
		// pixelStateT current = screen[pt.row][pt.col];
		while(screen[pt.row][positive] == current && positive<screen.size()){
			cout << screen[pt.row][positive] << " " ;
			if(screen[pt.row][positive] == White) screen[pt.row][positive] = Black;
			else screen[pt.row][positive] = White;
			positive++;
		}
	//Check the other direction with a for loop
		int negative = pt.col - 1;
		cout << negative << endl;
		while(screen[pt.row][negative] == current && negative>=0){
			cout << screen[pt.row][negative] << " " ;
			if(screen[pt.row][negative] == White) screen[pt.row][negative] = Black;
			else screen[pt.row][negative] = White;
			negative--;
		}

		pointT pt_above;
		pt_above.row = pt.row-1;
		pt_above.col = pt.col;

		pointT pt_below;
		pt_below.row = pt.row+1;
		pt_below.col = pt.col;

		FillRegion(pt_below, screen, current);
		FillRegion(pt_above, screen, current);
	}
//Then need to pass the initial pointT pt to two recursive functions one which increments the row by one, one which decrements it by one
}

void CheckPrint(grid &screen){
	vector< vector<pixelStateT> >::iterator row;
	vector<pixelStateT>::iterator col;
	for(row = screen.begin(); row !=screen.end(); row++){
		cout << "" << endl;
		for(col = row->begin(); col != row->end(); col++){
			cout << *col << " " ;
		}
	}
}

int main(){
	pixelStateT pixely = White;
	grid screen;
	pointT pt;
	pt.row = 10;
	pt.col = 10;

	screen.resize(pt.row);
	for (int i=0; i<pt.row; ++i){
		screen[i].resize(pt.col);
		for(int j=0; j<pt.col; ++j){
			if(j<3 && i<4 || j>7 && i>6) screen[i][j] = White;
			else screen[i][j] = Black;
		}
	} 


	CheckPrint(screen);
	cout << "Checking" << endl;
	
	pointT pt_change;
	pt_change.row = 1;
	pt_change.col = 1;

	pixelStateT current = screen[pt_change.row][pt_change.col];
 	FillRegion(pt_change, screen, current);
	CheckPrint(screen);

	return 0;
}




