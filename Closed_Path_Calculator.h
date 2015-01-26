#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include "Points.h"


using namespace std;

class Closed_Path_Calculator
{
public:
	Closed_Path_Calculator();
	~Closed_Path_Calculator();
	void load_points();
	void find_path();
	void display_path();
	void display_length();
	
private:
	Points next_pt;
	Points curr_pt;
	Points orig_pt;//point of origin
	list<Points> pts;//used to keep track of all the points
	list<int> path;//keeps the names of the points on the path
	double tot_dist;
	void calculate_path();//does main calculation!!!
};