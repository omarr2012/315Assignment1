#include "Closed_Path_Calculator.h"

Closed_Path_Calculator::Closed_Path_Calculator(){
}

Closed_Path_Calculator::~Closed_Path_Calculator(){}

void Closed_Path_Calculator::load_points(){
		string line = "";
		int pt_name = 0;
		
		while (getline(cin, line))
		{//if line starts with a # it is a comment ignore
			if (line[0]!='#' )
			{
				istringstream iss(line);
				float num;//temp value to hold number read in from file
				
				while ((iss>>num))//while not whitespace or newline
				{
					Points pt(pt_name);
					pt_name++;
					pt.x =num;
					iss>>num;
					pt.y = num;
					pts.push_back(pt);
				}
			}
		}
}

void Closed_Path_Calculator::find_path(){
	//next_pt = orig_pt = pts.front();//set starting pt
	list<Points>::iterator origin_it = set_origin();
	next_pt = orig_pt = *origin_it;
	path.push_back(next_pt.name);
	//pts.pop_front();
	pts.erase(origin_it);
	calculate_path();
}

void Closed_Path_Calculator::display_path(){
	while (!path.empty()){
		cout<<'P'<<path.front();
		path.pop_front();
		
		if (!path.empty())
			cout<<"->";
	}
	cout<<endl;
}

void Closed_Path_Calculator::display_length(){
	cout<<"Total Dist: "<<tot_dist<<endl;
}

//This Function does the main computation
void Closed_Path_Calculator::calculate_path(){
	 while(!pts.empty()){//perform until no more points
		curr_pt = next_pt;
		//bool found = false;
		double min = 999999999;
		list<Points>::iterator begin_itr, temp_itr;
		//find shortest path from curr_pt
		for (begin_itr=pts.begin();begin_itr!=pts.end() /*&& !found*/;++begin_itr){
			double dist = curr_pt.partial_dist_to_pt(*begin_itr);//gets distance between pts
			
			if (dist<min && dist != 0){//keep track of postion of shortest pt
				min = dist;
				temp_itr = begin_itr;
				//if (dist <=15) found = true;
			}
		}
		next_pt = *temp_itr;
		tot_dist += curr_pt.full_dist_to_pt(*temp_itr);
		path.push_back(next_pt.name);//keeping track of points
		pts.erase(temp_itr);//updating list
	 }
	 tot_dist += next_pt.full_dist_to_pt(orig_pt);
	 path.push_back(orig_pt.name);
}

list<Points>::iterator Closed_Path_Calculator::set_origin(){
		int x_min = 999999999, y_min = 999999999;
		list<Points>::iterator begin_itr, temp_itr;

		for (begin_itr=pts.begin();begin_itr!=pts.end();++begin_itr){
				
			if (begin_itr->x < x_min && begin_itr->y < y_min){//keep track of postion of shortest pt
				x_min = begin_itr->x;
				y_min = begin_itr->y;
				temp_itr = begin_itr;
			}
		}
		return temp_itr;
}