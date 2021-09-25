#include "instruction.hpp"


/**
 * default constructor
 */
Instruction::Instruction(){
    this->MC = "DNE";
    this->AC= "DNE";
    this->type = U;
}

/**
 * Parameterized constructor
 * 
 * @param instruction string containing instruction
 * @param format 0 for machine code, 1 for assembly code
 */
Instruction::Instruction(std::string instruction, InstructionFormat format){
    if(format == MachineCode){
        this->MC = instruction;
        this->AC = "DNE";
    }else{
        this->AC = instruction;
        this->MC = "DNE";
    }
    this->type = U;
}

/**
 * Gets instruction line in either machine code, or assembly. 
 * 
 * @param instruction string containing instruction
 * @param format 0 for machine code, 1 for assembly code
 */
void Instruction::setInstruction(std::string instruction, InstructionFormat format){

}

/**
 * Gets instruction line in either machine code, or assembly. 
 * 
 * @param format 0 for machine code, 1 for assembly code
 * @return string containing instruction in desired format, or "DNE" if desired format is not set.
 */
std::string Instruction::getInstruction(InstructionFormat format){
    return "";
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
