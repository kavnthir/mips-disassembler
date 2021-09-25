#include <iostream>
#include <fstream>

int main(int argc, char* argv[]{
	if(!disassemble){
		std::cout << argv[1] << " not found.\n";
	}
	return 0;
}	

bool disassemble(std::string filepath){
	ifstream input;
	std::string instruction;
	input.open(filepath);
	if(input.is_open()){
		while(getline(input,instruction){
			//construct
			//classify
			//convert
			//print
			//output to *.s
		}
	}else{
		return false;
	}
	input.close();
}
