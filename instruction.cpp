#include "instruction.hpp"


/**
 * default constructor
 */
Instruction::Instruction(){
    MC = "DNE";
    AC = "DNE";
    type = U;
    PC = 0;
    linenumber = -1;
    label = "N/A";
}

/**
 * Parameterized constructor
 * 
 * @param instruction string containing instruction, machine code should be in hex format
 * @param format 0 for machine code, 1 for assembly code
 */
Instruction::Instruction(std::string instruction, InstructionFormat format, int PC){
    if(format == MachineCode){
        MC = convertRadix(instruction, 0);
        AC = "DNE";
    }else{
        AC = instruction;
        MC = "DNE";
    }
    type = U;
    this->PC = PC;
    linenumber = -1;
    label = "N/A";
}

/**
 * Sets instruction line in either machine code, or assembly. 
 * 
 * @param instruction string containing instruction, machine code should be in hex format
 * @param format 0 for machine code, 1 for assembly code
 */
void Instruction::setInstruction(std::string instruction, InstructionFormat format){
    if(format == MachineCode){
        MC = convertRadix(instruction, 0);
    }else{
        AC = instruction;
    }
}

/**
 * Gets instruction line in either machine code, or assembly. 
 * 
 * @param format 0 for machine code, 1 for assembly code
 * @return string containing instruction in desired format, or "DNE" if desired format is not set.
 */
std::string Instruction::getInstruction(InstructionFormat format){
    return (format == MachineCode) ? MC : AC;
}

/**
 * Converts machine code into assembly code if possible
 * 
 * @return true if successfully, false otherwise
 */
bool Instruction::convertInstruction(){
    // create variables holding bit ranges for each field
    std::string opcode = MC.substr(0, 6);
    std::string rs = MC.substr(6, 5);
    std::string rt = MC.substr(11, 5);
    std::string rd = MC.substr(16, 5);
    std::string shamt = MC.substr(21, 5);
    std::string funct = MC.substr(26, 6);
    std::string immediate = MC.substr(16, 16);
    std::string address = MC.substr(6, 26); //might be wrong

    // Classify instruction
    if(opcode == "000000") type = R;
    else if(opcode == "000010" || opcode == "000011") type = J;
    else type = I; 

    switch (type) {
    case R:
        if(shamt == "00000"){
            AC = functcon.find(funct)->second + " ";
            AC += regcon.find(rd)->second + ", ";
            AC += regcon.find(rs)->second + ", ";
            AC += regcon.find(rt)->second;
        }else{
            AC = functcon.find(funct)->second + " ";
            AC += regcon.find(rd)->second + ", ";
            AC += regcon.find(rt)->second + ", ";
            AC += convertRadix(shamt, 1); 
        }
        break;
    case I:
        AC = opcon.find(opcode)->second + " ";
        if(opcode == "101011" || opcode == "100011"){
            AC += regcon.find(rt)->second + ", ";
            AC += convertRadix(immediate, 1);
            AC += '(' + regcon.find(rs)->second + ')';          
        }else if(opcode == "000100" || opcode == "000101"){
            AC += regcon.find(rs)->second + ", ";
            AC += regcon.find(rt)->second + ", ";
            linenumber = PC + 1 + std::stoi(convertRadix(immediate, 1));
            label = "Addr_" + convertRadix(std::to_string(4 * (PC + 1 + std::stoi(convertRadix(immediate, 1)))), 2);
            AC += label; 
            label += ":\n";
        }else{
            AC += regcon.find(rt)->second + ", ";
            AC += regcon.find(rs)->second + ", ";
            AC += convertRadix(immediate, 1);
        }
        break;
    case J:
        /* code */
        AC = "ans";
        break;
    case U:
        return false;
    }
    return true;
}

/**
 * Converts machine code from hex to binary
 * 
 * @param conversion 0 for hex to binary, 1 for binary to decimal
 * @return if convertion was successfully executed
 */
std::string Instruction::convertRadix(std::string input, int conversion){
    if(conversion == 0){
        std::string binary = "";
        for(char &s: input) binary += xtob.find(s)->second;
        return binary;
    }else if(conversion == 1){
        if(input[0] == '1'){
            int i;
            for (i = (int)input.length()-1 ; i >= 0 ; i--) if (input[i] == '1') break;
            for (int k = i-1 ; k >= 0; k--){
                if (input[k] == '1') input[k] = '0';
                else input[k] = '1';
            }
            return '-' + std::to_string(std::stoi(input, nullptr, 2));
        }
        return std::to_string(std::stoll(input, nullptr, 2));
    }else{
        std::stringstream stream;
        stream << std::setfill ('0') << std::setw(4) << std::hex << std::stoi(input);
        return stream.str();
    }
}