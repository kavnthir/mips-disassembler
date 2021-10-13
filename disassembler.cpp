#include "instruction.hpp"

bool disassemble(std::string ifile){
	std::ifstream input (ifile);

	if(input.is_open()){
		std::string ofile = ifile.substr(0, ifile.find(".obj")) +".s";
		std::ofstream output (ofile);
		std::map<int, std::string> labels;
		std::vector<std::string> lines;
		std::string line;
		int errorCount = 0;
		int PC = 0;

		while(std::getline(input,line)){
			Instruction instruction(line, MachineCode, PC);
			if(!instruction.convertInstruction()){
				std::cout << "Cannot disassemble " + line + " at line " + std::to_string(PC + 1) << '\n';
				errorCount++;
			}
			lines.push_back('\t' + instruction.getInstruction(AssemblyCode) + '\n');
			if(instruction.linenumber != -1) labels.insert({instruction.linenumber, instruction.label}); 
			PC++;
		}

		int offset = 0;
		for(auto it = labels.cbegin(); it != labels.cend(); ++it) {
			lines.insert(lines.begin() + it->first + offset, it->second);
			offset++;
		}
		
		for(int i = 0; i < lines.size(); i++) output << lines[i]; 

		output.close();
		input.close();

		if(errorCount != 0) {
			std::remove(ofile.c_str()); 
			exit(EXIT_FAILURE);
		}

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