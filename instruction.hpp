#ifndef _INSTRUCTION_HPP_
#define _INSTRUCTION_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <map>

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

        std::map<char, std::string> xtob {
            {'0', "0000"},
            {'1', "0001"},
            {'2', "0010"},
            {'3', "0011"},
            {'4', "0100"},
            {'5', "0101"},
            {'6', "0110"},
            {'7', "0111"},
            {'8', "1000"},
            {'9', "1001"},
            {'A', "1010"},
            {'B', "1011"},
            {'C', "1100"},
            {'D', "1101"},
            {'E', "1110"},
            {'F', "1111"}
        };

        /**
         * Classifies instruction in three catagories R, I, and J.
         * 
         * @return if classification was successfully executed
         */
        bool classifyInstruction();

        /**
         * Converts machine code from hex to binary
         * 
         * @return if convertion was successfully executed
         */
        std::string convertRadix(std::string MC);

};
#endif  