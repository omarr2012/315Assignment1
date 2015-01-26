#include "Points.h"

Points::Points(){}

Points::~Points(){}

//Uses Pythagres Theorm to calculate distance
//from the point that calls this function to 
//the point that is passed in.
double Points::dist_to_pt(Points pt){
	xd = x-pt.x;
	yd = y-pt.y;
	dist = sqrt(pow((double)xd,2)+pow((double)yd,2));
	return dist;
}