#include "instruction.hpp"


/**
 * default constructor
 */
Instruction::Instruction(){
    MC = "DNE";
    AC = "DNE";
    type = U;
    linenumber = -1;
    label = "N/A";
}

/**
 * Parameterized constructor
 * 
 * @param instruction string containing instruction, machine code should be in hex format
 * @param format 0 for machine code, 1 for assembly code
 */
Instruction::Instruction(std::string instruction, InstructionFormat format){
    if(format == MachineCode){
        MC = convertRadix(instruction, 0);
        AC = "DNE";
    }else{
        AC = instruction;
        MC = "DNE";
    }
    type = U;
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
    std::string immediate = MC.substr(16, 16); //might be wrong
    std::string address = MC.substr(6, 26); //might be wrong

    // Classify instruction
    if(opcode == "000000") type = R;
    else if(opcode == "000010" || opcode == "000011") type = J;
    else type = I; 

    std::cout << "opcode: " << opcode << '\n';
    std::cout << "functcode: " << funct << '\n';

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
            AC += "Addr_" + convertRadix(immediate, 2);
            linenumber = 0;
            label = convertRadix(immediate, 2);
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
        return std::to_string(std::stoll(input, nullptr, 2));
    }else{
        //convert decimal to hex
        return "0000";
    }
}