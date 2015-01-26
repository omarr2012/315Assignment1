#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include "Closed_Path_Calculator.h"

using namespace std;

int main(){
	try{
		Closed_Path_Calculator path_calc;
		path_calc.load_points();
		cout<<"\n--------------------------------\n";
		path_calc.find_path();
		path_calc.display_path();
		path_calc.display_length();
	}
	catch(exception &error){
		cerr<<"Error: "<<error.what()<<endl;
	}
}
