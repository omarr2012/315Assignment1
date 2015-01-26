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
				Points pt;//object that represents each point
				
				while ((iss>>num))//while not whitespace or newline
				{
					pt.name = pt_name;//pt name corresponds with line read
					pt_name++;
					pt.x =num;
					iss>>num;
					pt.y = num;
				}
				pts.push_back(pt);
			}
		}
}

void Closed_Path_Calculator::find_path(){
	next_pt = orig_pt = pts.front();//set starting pt
	
	path.push_back(next_pt.name);
	pts.pop_front();
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
		int min = 999999999;
		list<Points>::iterator begin_itr, min_itr;
		
		for (begin_itr=pts.begin();begin_itr!=pts.end();++begin_itr){
			double dist = 0;
			dist = curr_pt.dist_to_pt(*begin_itr);//gets distance between pts
			
			if (dist<min && dist != 0){//choose shortest path from curr_pt
				min = dist;
				next_pt = *begin_itr;
				min_itr = begin_itr;
			}
		}
		tot_dist +=min;
		path.push_back(next_pt.name);
		pts.erase(min_itr);
	 }
	 tot_dist += next_pt.dist_to_pt(orig_pt);
	 path.push_back(orig_pt.name);
}