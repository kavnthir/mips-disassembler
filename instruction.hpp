#ifndef _INSTRUCTION_HPP_
#define _INSTRUCTION_HPP_

#include <iostream>
#include <fstream>
#include <string>


enum InstructionFormat {MachineCode, AssemblyCode};

class Instruction{
    public:

        /**
         * default constructor
         */
        Instruction();

        /**
         * Parameterized constructor
         * 
         * @param instruction string containing instruction
         * @param format 0 for machine code, 1 for assembly code
         */
        Instruction(std::string instruction, InstructionFormat format);

        /**
         * Gets instruction line in either machine code, or assembly. 
         * 
         * @param instruction string containing instruction
         * @param format 0 for machine code, 1 for assembly code
         */
        void setInstruction(std::string instruction, InstructionFormat format);

        /**
         * Gets instruction line in either machine code, or assembly. 
         * 
         * @param format 0 for machine code, 1 for assembly code
         * @return string containing instruction in desired format, or "DNE" if desired format is not set.
         */
        std::string getInstruction(InstructionFormat format);

        /**
         * Converts machine code into assembly code if possible
         * 
         * @return true if successfully, false otherwise
         */
        bool convertInstruction();

    private:

        enum InstructionType {U, R, I, J};

        std::string MC;
        std::string AC;

        InstructionType type;

        /**
         * Classifies instruction in three catagories R, I, and J.
         * 
         * @return if classification was successfully executed
         */
        bool classifyInstruction();

};
#endif  