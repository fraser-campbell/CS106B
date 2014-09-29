/*
* Function: Shortestpath
* Usage: solve the shortest path solution for a maze
* –––––––––––––––––––––––––––––––
*/
#include <vector>
#include <string>
using namespace std;

void SolveMaze(pointT pt, vector<int> store, int counter)
{
	//Base case when outside the maze
	 if (OutsideMaze(pt)){
	 	if(store[0] > counter){
	 		store.push_back(counter)
	 	}
	 }

	 MarkSquare(pt);
	 for (directionT dir = North; dir <= West; dir=directionT(dir + 1)){
	 	//If you don't collide with a wall and there is a solution in this direction to the maze
	 	if (!WallExists(pt, dir)){
	 		//if not wall exists in the direction you intend to go search for a solution in this direction
	 		SolveMaze(AdjacentPoint(pt, dir)), store, counter+1);
	 	}
	 }

	UnmarkSquare(pt);
	// return false;
}




int ShortestPathLength(pointT pt){
 
 int shortest, len;
 //This only returns if we have exited the maze
 if (OutsideMaze(pt)){ return 0; }
 if (IsMarked(pt)){ return NoSolution; }
 
 //Initially set the shortest to no solution for each new stack
 shortest = NoSolution;
 
 MarkSquare(pt);
 for (directionT dir = North; dir <= West; dir=directionT(dir+1)){
 	if (!WallExists(pt, dir)){
 		//If no wall exists then the length is given by the solution from this point
 		len = ShortestPathLength(AdjacentPoint(pt, dir));
 		if (len < shortest){
 			//If this solution has a shorter length tha the shortest then new shortest
 			shortest = len;
 		}
 	}
 }
 
 UnmarkSquare(pt);
 if (shortest == NoSolution){return NoSolution;}
 //Once we exit the for loop for the lowest level of recursion if there was no solution discovered then return no solution to the level above
 else{return (shortest + 1);}
 //If there was a solution then increment the length by one for each stack that you close
}





int main(){

static const int NoSolution = 10000;

return 0;
}