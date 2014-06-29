/*
 * File: Minesweeper.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: [TODO: enter section leader here] 
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

typedef vector<vector<int> > minegrid;
typedef vector<vector<bool> > inputgrid;


void PrintGrid(minegrid &grid){
	int columns = grid[0].size();
	int rows = grid.size();
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

void PrintGridbool(inputgrid &grid){
	int columns = grid[0].size();
	int rows = grid.size();
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool randomly(){
	int random;
	if(rand()%2 !=0) return true;
	else return false;
}

void fill_grid(inputgrid &boolgrid){
	for(int i=0; i<6; i++){
		for(int j=0; j<6; j++){
			boolgrid[i][j] = randomly();
		}
	}
}

minegrid MakeGridOfCounts(inputgrid &boolgrid){
	minegrid mines(6, vector<int>(6));
	int columns = boolgrid[0].size();
	int rows = boolgrid.size();
	for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			int count = 0;
			for(int it_row=i-1; it_row<i+2; it_row++){
				for(int it_col=j-1; it_col<j+2; it_col++){
					if(it_col>=0 && columns>it_col && it_row>=0 && rows>it_row && boolgrid[it_row][it_col]==true){
						// cout << it_row << " " << it_col << endl;
						count++;
					}
				}
			}
			mines[i][j] = count;
		}
	}
	return mines;
}


int main(){
	inputgrid boolgrid(6, vector<bool>(6));
	fill_grid(boolgrid);
	PrintGridbool(boolgrid);
	minegrid mines = MakeGridOfCounts(boolgrid);
	PrintGrid(mines);
	return 0;
}

