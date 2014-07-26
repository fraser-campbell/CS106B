/*
 * File: RulerOTW.cpp
 * --------------------------
 * Name: Fraser Campbell
 * Section: This program reads the number of cannonballs given the number of layers
 * 
 */
 #include <iostream>
 #include <cmath>
 #include "graphics.h"
 #include "gevents.h"
 #include "gobjects.h"
 using namespace std;

void DrawRulerImpl(GWindow &gw, double x, double y, double w, double h);

void DrawRuler(double x, double y, double w, double h){
	GWindow gw;
	GLine *line;
	line = new GLine(x, y+h, x+w, y+h);
	gw.add(line);
	DrawRulerImpl(gw, x, y, w, h);
}

void  DrawRulerImpl(GWindow &gw, double x, double y, double w, double h){
	if(w<10);
	else{
		GLine *line;
		line = new GLine(x+w/2, y, x+w/2, y+h);
		gw.add(line);
		DrawRulerImpl(gw, x, y+h/2, w/2, h/2);
		DrawRulerImpl(gw, x+w/2, y+h/2, w/2, h/2);
	}
}

int main(){

	DrawRuler(60, 60, 200, 50);

	// GLine *line;
	// GWindow gw;
 // 	void initGraphics();
	// line = new GLine(10, 10, 50, 50);
	// gw.add(line, 10, 10);

 	return 0;
 }