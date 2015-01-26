#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

class Points
{
public:
	Points();
	~Points();
	int name;
	double dist_to_pt(Points pt1);
	int x, y;
	
private:
	int xd, yd;
	double dist;
};