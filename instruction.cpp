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
    if(opcode == "000000"){

    }else if(opcode == "010001"){

    }else{

    }
    // opcode = opcon.find(opcode)->second;

    AC = "this is a commit :))";
    return true;

    switch (type) {
    case R:
        /* code */
        break;
    case R0:
        /* code */
        break;
    case R17:
        /* code */
        break;
    case I:
        /* code */
        break;
    case J:
        /* code */
        break;
    case U:
        /* code */
        break;
    }
    return false;
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