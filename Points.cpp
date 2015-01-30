#include "Points.h"

Points::Points(){}

Points::Points(int pt_name) {
	name = pt_name;
}

Points::~Points(){}

double Points::partial_dist_to_pt(Points pt){
	xd = x-pt.x;
	yd = y-pt.y;
	dist = pow(xd,2)+pow(yd,2);//save sqare and sqrt for final distance calculation
	//dist = sqrt(pow((double)xd,2)+pow((double)yd,2));
	return dist;
}
//Uses Pythagres Theorm to calculate distance
//from the point that calls this function to 
//the point that is passed in.
double Points::full_dist_to_pt(Points pt){
	//for sanity clear temp variables
	xd = yd = dist = 0;
	xd = x-pt.x;
	yd = y-pt.y;
	dist = sqrt(pow((double)xd,2)+pow((double)yd,2));
	return dist;
}