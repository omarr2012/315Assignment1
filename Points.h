#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

class Points
{
public:
	Points();
	Points(int pt_name);
	~Points();
	int name;
	double partial_dist_to_pt(Points pt);//partial distance to pt
	double full_dist_to_pt(Points pt);
	int x, y;
	
private:
	int xd, yd;
	double dist;
};