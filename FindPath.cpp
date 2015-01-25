#include "FindPath.h"

FindPath::FindPath(){}

FindPath::FindPath(string File_name){
	load_points(File_name);
}

FindPath::~FindPath(){}

void FindPath::shortest_path(){
	next_pt = orig_pt = pts.front();
	path.push_back(next_pt.name);
	pts.pop_front();
	update_list();
}

void FindPath::update_list(){
	 while(!pts.empty()){
		curr_pt = next_pt;
		int min = 999999999;
		list<Points>::iterator begin_itr, min_itr;
		
		for (begin_itr=pts.begin();begin_itr!=pts.end();++begin_itr){
			double dist = 0;
			dist = curr_pt.dist_to_pt(*begin_itr);
			if (dist<min && dist != 0){
				min = dist;
				next_pt = *begin_itr;
				min_itr = begin_itr;
			}
		}
		cout<<"names :"<<next_pt.name<<endl;
		tot_dist +=min;
		path.push_back(next_pt.name);
		pts.erase(min_itr);
	 }
	 tot_dist += next_pt.dist_to_pt(orig_pt);
	 path.push_back(orig_pt.name);
}

void FindPath::display_path(){
	while (!path.empty()){
		cout<<'P'<<path.front()<<endl;
		path.pop_front();
	}
	cout<<"Total Dist: "<<tot_dist<<endl;
}

void FindPath::load_points(string File_name){
		string line = "";
		int pt_name = 0;
		
		while (getline(cin, line))
		{
			if (line[0]!='#' )
			{
				istringstream iss(line);
				float num;
				Points pt;
				
				while ((iss>>num))//while not whitespace or newline
				{
					pt.name = pt_name;
					pt_name++;
					pt.x =num;
					iss>>num;
					pt.y = num;
				}
				pts.push_back(pt);
			}
		}
}

void FindPath::debug_display(int level, int line_number){
	cout<<"\nDebug "<<level<<" Line "<<line_number<<endl;
	
	switch(level){
		case 0:
			for(list<Points>::iterator begin_itr=pts.begin();begin_itr!=pts.end();++begin_itr){
				cout<<begin_itr->name<<endl;
			}
			break;
			default:
			cout<<"\nDebug level non-existent\n";
			break;
	}
	cout<<"DebugEnd\n";
}