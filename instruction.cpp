#include "instruction.hpp"


/**
 * default constructor
 */
Instruction::Instruction(){
    MC = "DNE";
    AC= "DNE";
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
        MC = convertRadix(instruction);
        AC = "DNE";
    }else{
        AC = instruction;
        MC = "DNE";
    }
    type = U;
}

/**
 * Gets instruction line in either machine code, or assembly. 
 * 
 * @param instruction string containing instruction, machine code should be in hex format
 * @param format 0 for machine code, 1 for assembly code
 */
void Instruction::setInstruction(std::string instruction, InstructionFormat format){
    if(format == MachineCode){
        MC = convertRadix(instruction);
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
 * Classifies instruction in three catagories R, I, and J.
 * 
 * @return if classification was successfully executed
 */
bool Instruction::classifyInstruction(){
    return false;
}

/**
 * Converts machine code into assembly code if possible
 * 
 * @return true if successfully, false otherwise
 */
bool Instruction::convertInstruction(){
    return false;
}

/**
 * Converts machine code from hex to binary
 * 
 * @return if convertion was successfully executed
 */
std::string Instruction::convertRadix(std::string MC){
    std::string binary = "";
    for(char &s: MC) binary += xtob.find(s)->second;
    return binary;
}