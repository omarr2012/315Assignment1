#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include "Points.h"


using namespace std;

class FindPath
{
public:
	FindPath();
	FindPath(string File_name);
	~FindPath();
	void shortest_path();
	void min_distance();
	void display_path();
	void display_length();
private:
	Points next_pt, curr_pt, orig_pt;
	list<Points> pts;
	list<int> path;
	double tot_dist=0;
	void load_points(string file_name);
	void update_list();
	void debug_display(int level, int line_number);
};