#ifndef _INSTRUCTION_HPP_
#define _INSTRUCTION_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <bitset>
#include <vector>

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
        Instruction(std::string instruction, InstructionFormat format, int PC);

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

        int linenumber;
        std::string label;
        
    private:

        enum InstructionType {U, R, I, J};

        std::string MC;
        std::string AC;
        int PC;

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
            {"001000", "addi"},
            {"001001", "addiu"},
            {"001100", "andi"},
            {"000100", "beq"},
            {"000101", "bne"},
            {"000010", "j"},
            {"000011", "jal"},
            {"100100", "lbu"},
            {"100101", "lhu"},
            {"110000", "ll"},
            {"001111", "lui"},
            {"100011", "lw"},
            {"001101", "ori"},
            {"001010", "slti"},
            {"001011", "sltiu"},
            {"101000", "sb"},
            {"100110", "sc"},
            {"101001", "sh"},
            {"101011", "sw"}
        };

        // used to map register numbers in binary to $X format
        std::map<std::string, std::string> regcon {
            {"00000", "$zero"},
            {"00001", "$at"},
            {"00010", "$v0"},
            {"00011", "$v1"},
            {"00100", "$a0"},
            {"00101", "$a1"},
            {"00110", "$a2"},
            {"00111", "$a3"},
            {"01000", "$t0"},
            {"01001", "$t1"},
            {"01010", "$t2"},
            {"01011", "$t3"},
            {"01100", "$t4"},
            {"01101", "$t5"},
            {"01110", "$t6"},
            {"01111", "$t7"},
            {"10000", "$s0"},
            {"10001", "$s1"},
            {"10010", "$s2"},
            {"10011", "$s3"},
            {"10100", "$s4"},
            {"10101", "$s5"},
            {"10110", "$s6"},
            {"10111", "$s7"},
            {"11000", "$t8"},
            {"11001", "$t9"},
            {"11010", "$k0"},
            {"11011", "$k1"},
            {"11100", "$gp"},
            {"11101", "$sp"},
            {"11110", "$fp"},
            {"11111", "$ra"}
        };

        // used to map func0 code to the right operation
        std::map<std::string, std::string> functcon {
            {"100000", "add"},
            {"100001", "addu"},
            {"100100", "and"},
            {"001000", "jr"},
            {"100111", "nor"},
            {"100101", "or"},
            {"101010", "slt"},
            {"101011", "sltu"},
            {"000000", "sll"},
            {"000010", "srl"},
            {"100010", "sub"},
            {"100011", "subu"}
        };
};
#endif  