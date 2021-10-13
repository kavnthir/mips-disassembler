#include "instruction.hpp"


/**
 * default constructor
 */
Instruction::Instruction(){
    MC = "DNE";
    AC = "DNE";
    type = U;
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
    // Classify instruction
    std::string opcode = MC.substr(0, 6);
    std::string rs = MC.substr(6, 5);
    std::string rt = MC.substr(11, 5);
    std::string rd = MC.substr(16, 5);
    std::string shamt = MC.substr(21, 5);
    std::string funct = MC.substr(26, 6);
    std::string immediate = MC.substr(16, 16); //might be wrong
    std::string address = MC.substr(6, 26); //might be wrong

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
            //code if there is a shift amount.
        }
        break;
    case I:
        /* code */
        AC = "ans";
        break;
    case J:
        /* code */
        AC = "ans";
        break;
    case U:
        /* code */
        AC = "ans";
        break;
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
        // convert binary to decimal
        return "";
    }else{
        //convert decimal to hex
        return "";
    }
}