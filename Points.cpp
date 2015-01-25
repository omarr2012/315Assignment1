#include "Points.h"

Points::Points(){}

Points::~Points(){}

double Points::dist_to_pt(Points pt){
cout<<x<<"  "<<y<<"  "<<pt.x<<"  "<<pt.y;
	xd = x-pt.x;
	yd = y-pt.y;
	//cout<<" sqrt "<<xd<<"  "<<"  "<<yd;
	dist = sqrt(pow((double)xd,2)+pow((double)yd,2));
	cout<<"    ->"<<dist<<endl;
	return dist;
}