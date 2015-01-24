#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

int main(){
	try{
		string buff;
		
		cout<<"Your file contains:\n";
		
		while(getline(cin, buff)){
			if (buff[0] != '#'){
				cout<<buff<<'\n';
			}
		}

	}
	catch(exception &error){
		cerr << "Error: " << error.what() << endl;
	}
}
