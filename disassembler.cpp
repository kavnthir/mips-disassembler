#include "instruction.hpp"

bool disassemble(std::string filepath){
	std::ifstream input (filepath);
	std::string instruction;
	if(input.is_open()){
		std::ofstream output (filepath.substr(0, filepath.find(".obj")) +".s");
		std::map<int, std::string> labels;
		std::vector<std::string> lines;
		int PC = 0;
		while(std::getline(input,instruction)){
			Instruction instruction(instruction, MachineCode, PC);
			instruction.convertInstruction();
			lines.push_back('\t' + instruction.getInstruction(AssemblyCode) + '\n');
			if(instruction.linenumber != -1){
				labels.insert({instruction.linenumber, instruction.label});
			}
			PC++;
		}
		int offset = 0;
		for(auto it = labels.cbegin(); it != labels.cend(); ++it) {
			lines.insert(lines.begin() + it->first + offset, it->second);
			offset++;
		}
		for(int i = 0; i < lines.size(); i++){
			output << lines[i];
		}
		output.close();
		input.close();
		return true;
	}else{
		return false;
	}
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