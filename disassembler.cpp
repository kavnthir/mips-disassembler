#include "instruction.hpp"

int main(int argc, char* argv[]){
	if(!disassemble(argv[1])){
		std::cout << argv[1] << " not found.\n";
	}
	return 0;
}	

bool disassemble(std::string filepath){
	std::ifstream input;
	std::string instruction;
	input.open(filepath);
	if(input.is_open()){
		while(std::getline(input,instruction)){
			//construct
			//classify
			//convert
			//output to *.s
		}
	}else{
		return false;
	}
	input.close();
}
