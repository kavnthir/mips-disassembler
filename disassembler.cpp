#include "instruction.hpp"

bool disassemble(std::string filepath){
	std::ifstream input;
	std::string instruction;
	input.open(filepath);
	if(input.is_open()){
		while(std::getline(input,instruction)){
			Instruction instruction(instruction, MachineCode);
			instruction.convertInstruction();
			std::cout << instruction.getInstruction(AssemblyCode) << "\n";
			// store assembly code to *.s
		}
		return true;
	}else{
		return false;
	}
	input.close();
}

int main(int argc, char* argv[]){
	if(argc == 1){
		std::cout << "please specify a *.obj file.";
		return -1;
	}else if(!disassemble(argv[1])){
		std::cout << argv[1] << " not found.\n";
		return -1;
	}else{
		std::cout << "disassembled code outputted to *.s\n";
		return 0;
	}
}	