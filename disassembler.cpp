#include "instruction.hpp"

bool disassemble(std::string filepath){
	std::ifstream input (filepath);
	std::string instruction;
	if(input.is_open()){
		std::ofstream output (filepath.substr(0, filepath.find(".obj")) +".s");
		while(std::getline(input,instruction)){
			Instruction instruction(instruction, MachineCode);
			instruction.convertInstruction();
			output << '\t' << instruction.getInstruction(AssemblyCode) << '\n';
		}
		output.close();
		input.close();
		return true;
	}else{
		return false;
	}
}

void labler(){
	//function that takes datastructures of array locations and inserts them in to output file.
}

int main(int argc, char* argv[]){
	std::string filepath = argv[1];
	if(argc == 1){
		std::cout << "please specify a *.obj file.\n";
		return -1;
	}else if(!disassemble(filepath)){
		std::cout << filepath << " not found.\n";
		return -1;
	}else{
		std::cout << "disassembled code outputted to " + filepath.substr(0, filepath.find(".obj")) + ".s\n";
		return 0;
	}
}	