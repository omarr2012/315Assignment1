#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

int main(){
	try{
		string buff;
		string file_in="inputfile.txt";
		
		ifstream input_file(file_in);
		streambuf *cinbuf = cin.rdbuf(); //save original buffer
		cin.rdbuf(input_file.rdbuf()); //redirect std::cin to file
		
		cout<<"Your file contains:\n";
		while(getline(cin, buff)){
			if (buff[0] != '#'){
				cout<<buff<<'\n';
			}
		}

		cin.rdbuf(cinbuf);
		input_file.close();
	}
	catch(exception &error){
		cerr << "Error: " << error.what() << endl;
	}
}
