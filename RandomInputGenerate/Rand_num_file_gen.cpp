#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include "FindPath.h"

using namespace std;

int main(){
	
	FindPath fp("testcase1.txt");
	cout<<"\n--------------------------------\n";
	fp.shortest_path();
	fp.display_path();
}
