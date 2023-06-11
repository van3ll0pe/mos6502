#pragma once
#ifndef __CPU_HPP__
#define __CPU_HPP__

#include <stdint.h>
#include <array>
#include <string>
#include <vector>
#include <memory>

#define MEMORY_SIZE 0x10000
#define STACK 0x0100

#define NEGATIVE_FLAG   0b10000000
#define OVERFLOW_FLAG   0b01000000
#define UNUSED_FLAG     0b00100000
#define BREAK_FLAG      0b00010000
#define DECIMAL_FLAG    0b00001000
#define INTERRUPT_FLAG  0b00000100
#define ZERO_FLAG       0b00000010
#define CARRY_FLAG      0b00000001

#define IRQ_VECTOR_L 0xFFFE
#define IRQ_VECTOR_H 0xFFFF
#define NMI_VECTOR_L 0xFFFA
#define NMI_VECTOR_H 0xFFFB
#define RST_VECTOR_L 0xFFFC
#define RST_VECTOR_H 0xFFFD




namespace mos6502
{
    class Cpu
    {
        public:
            Cpu();
            virtual ~Cpu();
        
        private:
            uint8_t A;
            uint8_t X;
            uint8_t Y;
            uint8_t SP;     //STACK pointer [0x100 to 0x1FF]
            uint8_t SR;     //Status Register (P)
            uint16_t PC;    //Program Counter

            uint8_t opcode;             //the current opcode running
            uint16_t address;           //the address to get the value from addressing mode
            uint8_t value_address;      //the value at the address
            uint8_t cycles;

        //##### fetch #####
        void fetch_opcode();    //fetch the opcode value
        void fetch_value();     //fetch value from addressing mode in the memory

        //##### MEMORY #####
        std::array<uint8_t, MEMORY_SIZE> memory;
        uint8_t mem_read(uint16_t address);
        void mem_write(uint16_t address, uint8_t value);

        
        //##### FLAG management #####
            uint8_t get_flag(uint8_t FLAG);
            void set_flag(uint8_t FLAG);
            void clear_flag(uint8_t FLAG);
            void check_flag(uint8_t FLAG, bool condition);

        //##### ADDRESSING MODE FUNCTIONS #####
    private:
        void IMPLIED();
        void IMMEDIATE();
        void ABSOLUTE();
        void ZEROPAGE();
        void ABSOLUTE_X();
        void ABSOLUTE_Y();
        void ZEROPAGE_X();
        void ZEROPAGE_Y();
        void INDIRECT();
        void INDIRECT_X();
        void INDIRECT_Y();
        void RELATIVE();

        //##### RUN INSTRUCTIONS #####
    public:
        void run();
        void load(std::vector<uint8_t> &instr, uint16_t addr);
        void set_NMI_VECTOR(uint16_t value);
        void set_IRQ_VECTOR(uint16_t value);
        void set_RESET_VECTOR(uint16_t value);
        bool is_BRK();

    private:
        void execute_opcode();

        //##### INTERRUPTIONS #####
    public:
        void IRQ();
        void NMI();
        void RESET();

        //##### STACK #####
    private:
        void push_8b(uint8_t data);
        void push_16b(uint16_t data);
        uint8_t pull_8b();
        uint16_t pull_16b();

        //##### INSTRUCTIONS FUNCTIONS #####

        void ADC();
        void AND();
        void ASL();
        void ASL_A();
        void BCC();
        void BCS();
        void BEQ();
        void BIT();
        void BMI();
        void BNE();
        void BPL();
        void BRK();
        void BVC();
        void BVS();
        void CLC();
        void CLD();
        void CLI();
        void CLV();
        void CMP();
        void CPX();
        void CPY();
        void DEC();
        void DEX();
        void DEY();
        void EOR();
        void INC();
        void INX();
        void INY();
        void JMP();
        void JSR();
        void LDA();
        void LDX();
        void LDY();
        void LSR();
        void LSR_A();
        void NOP();
        void ORA();
        void PHA();
        void PHP();
        void PLA();
        void PLP();
        void ROL();
        void ROL_A();
        void ROR();
        void ROR_A();
        void RTI();
        void RTS();
        void SBC();
        void SEC();
        void SED();
        void SEI();
        void STA();
        void STX();
        void STY();
        void TAX();
        void TAY();
        void TSX();
        void TXA();
        void TXS();
        void TYA();

    };
}

#endif //__CPU_HPP__