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
         * @param instruction string containing instruction, machine code should be in hex format
         * @param format 0 for machine code, 1 for assembly code
         */
        Instruction(std::string instruction, InstructionFormat format);

        /**
         * Gets instruction line in either machine code, or assembly. 
         * 
         * @param instruction string containing instruction, machine code should be in hex format
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

        enum InstructionType {U, R, R0, R17, I, J};

        std::string MC;
        std::string AC;

        InstructionType type;


        /**
         * Converts machine code from hex to binary
         * 
         * @param conversion 0 for hex to binary, 1 for binary to decimal
         * @return if convertion was successfully executed
         */
        std::string convertRadix(std::string MC, int conversion);

    private:

        // used to map hexadecimal to binary
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
            {'a', "1010"},
            {'b', "1011"},
            {'c', "1100"},
            {'d', "1101"},
            {'e', "1110"},
            {'f', "1111"}
        };

        // used to convert regular opcode to the right operations
        std::map<std::string, std::string> opcon {
            {"0000", "0000"},
            {"0001", "0001"},
            {"0010", "0010"},
            {"0011", "0011"},
            {"0100", "0100"},
            {"0101", "0101"},
            {"0110", "0110"},
            {"0111", "0111"},
            {"1000", "1000"},
            {"1001", "1001"},
            {"1010", "1010"},
            {"1011", "1011"},
            {"1100", "1100"},
            {"1101", "1101"},
            {"1110", "1110"},
            {"1111", "1111"}
        };

        // used to map register numbers in binary to $X format
        std::map<std::string, std::string> regcon {
            {"0000", "0000"},
            {"0001", "0001"},
            {"0010", "0010"},
            {"0011", "0011"},
            {"0100", "0100"},
            {"0101", "0101"},
            {"0110", "0110"},
            {"0111", "0111"},
            {"1000", "1000"},
            {"1001", "1001"},
            {"1010", "1010"},
            {"1011", "1011"},
            {"1100", "1100"},
            {"1101", "1101"},
            {"1110", "1110"},
            {"1111", "1111"}
        };

        // used to map func0 code to the right operation
        std::map<std::string, std::string> funccon0 {
            {"0000", "0000"},
            {"0001", "0001"},
            {"0010", "0010"},
            {"0011", "0011"},
            {"0100", "0100"},
            {"0101", "0101"},
            {"0110", "0110"},
            {"0111", "0111"},
            {"1000", "1000"},
            {"1001", "1001"},
            {"1010", "1010"},
            {"1011", "1011"},
            {"1100", "1100"},
            {"1101", "1101"},
            {"1110", "1110"},
            {"1111", "1111"}
        };

        // used to map func17 code to the right operation
        std::map<std::string, std::string> funccon17 {
            {"0000", "0000"},
            {"0001", "0001"},
            {"0010", "0010"},
            {"0011", "0011"},
            {"0100", "0100"},
            {"0101", "0101"},
            {"0110", "0110"},
            {"0111", "0111"},
            {"1000", "1000"},
            {"1001", "1001"},
            {"1010", "1010"},
            {"1011", "1011"},
            {"1100", "1100"},
            {"1101", "1101"},
            {"1110", "1110"},
            {"1111", "1111"}
        };

        // used to map opcode to type
        std::map<std::string, std::string> otot {
            {"0000", "0000"},
            {"0001", "0001"},
            {"0010", "0010"},
            {"0011", "0011"},
            {"0100", "0100"},
            {"0101", "0101"},
            {"0110", "0110"},
            {"0111", "0111"},
            {"1000", "1000"},
            {"1001", "1001"},
            {"1010", "1010"},
            {"1011", "1011"},
            {"1100", "1100"},
            {"1101", "1101"},
            {"1110", "1110"},
            {"1111", "1111"}
        };
};
#endif  