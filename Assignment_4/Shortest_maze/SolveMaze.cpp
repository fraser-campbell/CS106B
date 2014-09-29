/*
* Function: SolveMaze
* Usage: if (SolveMaze(pt)) . . .
* –––––––––––––––––––––––––––––––
* This function attempts to generate a solution to the current
* maze from point pt. SolveMaze returns true if the maze has
* a solution and false otherwise. The implementation uses
* recursion to solve the sub-mazes that result from marking the
* current square and moving one step along each open passage.
*/

bool SolveMaze(pointT pt)
{
 if (OutsideMaze(pt))
 return true;
 if (IsMarked(pt))
 return false;
 MarkSquare(pt);
 for (directionT dir = North; dir <= West; dir=directionT(dir + 1))
 {
 if (!WallExists(pt, dir) && SolveMaze(AdjacentPoint(pt, dir)))
 {
 return true;
 }
 }
 UnmarkSquare(pt);
 return false;
}