#include "cpu.hpp"
#include <iostream>
#include <stdio.h>

namespace mos6502
{
    Cpu::Cpu()
    {

        this->memory.fill(0);

        this->A = 0;
        this->X = 0;
        this->Y = 0;
        this->PC = (mem_read(RST_VECTOR_H) << 8) | mem_read(RST_VECTOR_L);
        this->SR = 0b00100000; //bit 5 always set to 1
        this->SP = 0xFF;
        


        //fill the instruction table for illegal opcode
        
    }

    Cpu::~Cpu() {}

    void
    Cpu::execute_opcode()
    {
        fetch_opcode();

        switch(this->opcode)
        {
            case 0x00: //BRK
                        cycles = 7;
                        IMPLIED();
                        BRK();
                        break;

            case 0x01:  //ORA
                        cycles = 6;
                        INDIRECT_X();
                        ORA();
                        break;

            case 0x05: //ORA
                        cycles = 3;
                        ZEROPAGE();
                        ORA();
                        break;

            case 0x06: //ASL
                        cycles = 5;
                        ZEROPAGE();
                        ASL();
                        break;

            case 0x08:  //PHP
                        cycles = 3;
                        IMPLIED();
                        PHP();
                        break;

            case 0x09:  //ORA 
                        cycles = 2;
                        IMMEDIATE();
                        ORA();
                        break;

            case 0x0A:  //ASL
                        cycles = 2;
                        IMPLIED();
                        ASL_A();
                        break;

            case 0x0D:  //ORA
                        cycles = 4;
                        ABSOLUTE();
                        ORA();
                        break;

            case 0x0E:  //ASL
                        cycles = 6;
                        ABSOLUTE();
                        ASL();
                        break;
            
            case 0x10:  //BPL
                        cycles = 2;
                        RELATIVE();
                        BPL();
                        break;

            case 0x11:  //ORA
                        cycles = 5;
                        INDIRECT_Y();
                        ORA();
                        break;

            case 0x15:  //ORA
                        cycles = 4;
                        ZEROPAGE_X();
                        ORA();
                        break;

            case 0x16:  //ASL
                        cycles = 6;
                        ZEROPAGE_X();
                        ASL();
                        break;

            case 0x18:  //CLC
                        cycles = 2;
                        IMPLIED();
                        CLC();
                        break;

            case 0x19:  //ORA
                        cycles = 4;
                        ABSOLUTE_Y();
                        ORA();
                        break;

            case 0x1D:  //ORA
                        cycles = 4;
                        ABSOLUTE_X();
                        ORA();
                        break;

            case 0x1E:  //ASL
                        ABSOLUTE_X();
                        cycles = 7;
                        ASL();
                        break;
            
            case 0x20:  //JSR
                        cycles = 6;
                        ABSOLUTE();
                        JSR();
                        break;

            case 0x21:  //AND
                        cycles = 6;
                        INDIRECT_X();
                        AND();
                        break;

            case 0x24:  //BIT
                        cycles = 3;
                        ZEROPAGE();
                        BIT();
                        break;

            case 0x25:  //AND
                        cycles = 3;
                        ZEROPAGE();
                        AND();
                        break;

            case 0x26:  //ROL
                        cycles = 5;
                        ZEROPAGE();
                        ROL();
                        break;

            case 0x28:  //PLP
                        cycles = 4;
                        IMPLIED();
                        PLP();
                        break;

            case 0x29:  //AND
                        cycles = 2;
                        IMMEDIATE();
                        AND();
                        break;

            case 0x2A:  //ROL
                        cycles = 2;
                        IMPLIED();
                        ROL_A();
                        break;

            case 0x2C:  //BIT
                        cycles = 4;
                        ABSOLUTE();
                        BIT();
                        break;

            case 0x2D:  //AND
                        cycles = 4;
                        ABSOLUTE();
                        AND();
                        break;

            case 0x2E:  //ROL
                        cycles = 6;
                        ABSOLUTE();
                        ROL();
                        break;

            case 0x30:  //BMI
                        cycles = 2;
                        RELATIVE();
                        BMI();
                        break;

            case 0x31:  //AND
                        cycles = 5;
                        INDIRECT_Y();
                        AND();
                        break;

            case 0x35:  //AND
                        cycles = 4;
                        ZEROPAGE_X();
                        AND();
                        break;

            case 0x36:  //ROL
                        cycles = 6;
                        ZEROPAGE_X();
                        ROL();
                        break;

            case 0x38:  //SEC
                        cycles = 2;
                        IMPLIED();
                        SEC();
                        break;

            case 0x39:  //AND
                        cycles = 4;
                        ABSOLUTE_Y();
                        AND();
                        break;

            case 0x3D:  //AND
                        cycles = 4;
                        ABSOLUTE_X();
                        AND();
                        break;

            case 0x3E:  //ROL
                        ABSOLUTE_X();
                        cycles = 7;
                        ROL();
                        break;
            

            case 0x40:  //RTI
                        cycles = 6;
                        IMPLIED();
                        RTI();
                        break;

            case 0x41:  //EOR
                        cycles = 6;
                        INDIRECT_X();
                        EOR();
                        break;

            case 0x45:  //EOR
                        cycles = 3;
                        ZEROPAGE();
                        EOR();
                        break;

            case 0x46:  //LSR
                        cycles = 5;
                        ZEROPAGE();
                        LSR();
                        break;

            case 0x48:  //PHA
                        cycles = 3;
                        IMPLIED();
                        PHA();
                        break;

            case 0x49:  //EOR
                        cycles = 2;
                        IMMEDIATE();
                        EOR();
                        break;

            case 0x4A:  //LSR
                        cycles = 2;
                        IMPLIED();
                        LSR_A();
                        break;

            case 0x4C:  //JMP
                        cycles = 3;
                        ABSOLUTE();
                        JMP();
                        break;

            case 0x4D:  //EOR
                        cycles = 4;
                        ABSOLUTE();
                        EOR();
                        break;

            case 0x4E:  //LSR
                        cycles = 6;
                        ABSOLUTE();
                        LSR();
                        break;
            
            
            case 0x50:  //BVC
                        cycles = 2;
                        RELATIVE();
                        BVC();
                        break;

            case 0x51:  //EOR
                        cycles = 5;
                        INDIRECT_Y();
                        EOR();
                        break;

            case 0x55:  //EOR
                        cycles = 4;
                        ZEROPAGE_X();
                        EOR();
                        break;

            case 0x56:  //LSR
                        cycles = 6;
                        ZEROPAGE_X();
                        LSR();
                        break;

            case 0x58:  //CLI
                        cycles = 2;
                        IMPLIED();
                        CLI();
                        break;

            case 0x59:  //EOR
                        cycles = 4;
                        ABSOLUTE_Y();
                        EOR();
                        break;

            case 0x5D:  //EOR
                        cycles = 4;
                        ABSOLUTE_X();
                        EOR();
                        break;

            case 0x5E:  //LSR
                        ABSOLUTE_X();
                        cycles = 7; //after addressing mod because not add +1 to the cycle. there is not *
                        LSR();
                        break;
            

            case 0x60:  //RTS
                        cycles = 6;
                        IMPLIED();
                        RTS();
                        break;

            case 0x61:  //ADC
                        cycles = 6;
                        INDIRECT_X();
                        ADC();
                        break;

            case 0x65:  //ADC
                        cycles = 3;
                        ZEROPAGE();
                        ADC();
                        break;

            case 0x66:  //ROR
                        cycles = 5;
                        ZEROPAGE();
                        ROR();
                        break;

            case 0x68:  //PLA
                        cycles = 4;
                        IMPLIED();
                        PLA();
                        break;

            case 0x69:  //ADC
                        cycles = 2;
                        IMMEDIATE();
                        ADC();
                        break;

            case 0x6A:  //ROR
                        cycles = 2;
                        IMPLIED();
                        ROR_A();
                        break;

            case 0x6C:  //JMP
                        cycles = 5;
                        INDIRECT();
                        JMP();
                        break;

            case 0x6D:  //ADC
                        cycles = 4;
                        ABSOLUTE();
                        ADC();
                        break;

            case 0x6E:  //ROR
                        cycles = 6;
                        ABSOLUTE();
                        ROR();
                        break;

            case 0x70:  //BVS
                        cycles = 2;
                        RELATIVE();
                        BVS();
                        break;

            case 0x71:  //ADC
                        cycles = 5;
                        INDIRECT_Y();
                        ADC();
                        break;

            case 0x75:  //ADC
                        cycles = 4;
                        ZEROPAGE_X();
                        ADC();
                        break;

            case 0x76:  //ROR
                        cycles = 6;
                        ZEROPAGE_X();
                        ROR();
                        break;

            case 0x78:  //SEI
                        cycles = 2;
                        IMPLIED();
                        SEI();
                        break;

            case 0x79:  //ADC
                        cycles = 4;
                        ABSOLUTE_Y();
                        ADC();
                        break;

            case 0x7D:  //ADC
                        cycles = 4;
                        ABSOLUTE_X();
                        ADC();
                        break;

            case 0x7E:  //ROR
                        ABSOLUTE_X();
                        cycles = 7;
                        ROR();
                        break;
            
            case 0x81:  //STA
                        cycles = 6;
                        INDIRECT_X();
                        STA();
                        break;

            case 0x84:  //STY
                        cycles = 3;
                        ZEROPAGE();
                        STY();
                        break;

            case 0x85:  //STA
                        cycles = 3;
                        ZEROPAGE();
                        STA();
                        break;

            case 0x86:  //STX
                        cycles = 3;
                        ZEROPAGE();
                        STX();
                        break;

            case 0x88:  //DEY
                        cycles = 2;
                        IMPLIED();
                        DEY();
                        break;

            case 0x8A:  //TXA
                        cycles = 2;
                        IMPLIED();
                        TXA();
                        break;

            case 0x8C:  //STY
                        cycles = 4;
                        ABSOLUTE();
                        STY();
                        break;

            case 0x8D:  //STA
                        cycles = 4;
                        ABSOLUTE();
                        STA();
                        break;

            case 0x8E:  //STX
                        cycles = 4;
                        ABSOLUTE();
                        STX();
                        break;
            
            case 0x90:  //BCC
                        cycles = 2;
                        RELATIVE();
                        BCC();
                        break;

            case 0x91:  //STA
                        INDIRECT_Y();
                        cycles = 6;
                        STA();
                        break;

            case 0x94:  //STY
                        cycles = 4;
                        ZEROPAGE_X();
                        STY();
                        break;

            case 0x95:  //STA
                        cycles = 4;
                        ZEROPAGE_X();
                        STA();
                        break;

            case 0x96:  //STX
                        cycles = 4;
                        ZEROPAGE_Y();
                        STX();
                        break;

            case 0x98:  //TYA
                        cycles = 2;
                        IMPLIED();
                        TYA();
                        break;

            case 0x99:  //STA
                        ABSOLUTE_Y();
                        cycles = 5;
                        STA();
                        break;

            case 0x9A:  //TXS
                        cycles = 2;
                        IMPLIED();
                        TXS();
                        break;

            case 0x9D:  //STA
                        ABSOLUTE_X();
                        cycles = 5;
                        STA();
                        break;
            
            case 0xA0:  //LDY
                        cycles = 2;
                        IMMEDIATE();
                        LDY();
                        break;

            case 0xA1:  //LDA
                        cycles = 6;
                        INDIRECT_X();
                        LDA();
                        break;

            case 0xA2:  //LDX
                        cycles = 2;
                        IMMEDIATE();
                        LDX();
                        break;

            case 0xA4:  //LDY
                        cycles = 3;
                        ZEROPAGE();
                        LDY();
                        break;

            case 0xA5:  //LDA
                        cycles = 3;
                        ZEROPAGE();
                        LDA();
                        break;

            case 0xA6:  //LDX
                        cycles = 3;
                        ZEROPAGE();
                        LDX();
                        break;

            case 0xA8:  //TAY
                        cycles = 2;
                        IMPLIED();
                        TAY();
                        break;

            case 0xA9:  //LDA
                        cycles = 2;
                        IMMEDIATE();
                        LDA();
                        break;

            case 0xAA:  //TAX
                        cycles = 2;
                        IMPLIED();
                        TAX();
                        break;

            case 0xAC:  //LDY
                        cycles = 4;
                        ABSOLUTE();
                        LDY();
                        break;

            case 0xAD:  //LDA
                        cycles = 4;
                        ABSOLUTE();
                        LDA();
                        break;

            case 0xAE:  //LDX
                        cycles = 4;
                        ABSOLUTE();
                        LDX();
                        break;
            
            case 0xB0:  //BCS
                        cycles = 2;
                        RELATIVE();
                        BCS();
                        break;

            case 0xB1:  //LDA
                        cycles = 5;
                        INDIRECT_Y();
                        LDA();
                        break;

            case 0xB4:  //LDY
                        cycles = 4;
                        ZEROPAGE_X();
                        LDY();
                        break;

            case 0xB5:  //LDA
                        cycles = 4;
                        ZEROPAGE_X();
                        LDA();
                        break;

            case 0xB6:  //LDX
                        cycles = 4;
                        ZEROPAGE_Y();
                        LDX();
                        break;

            case 0xB8:  //CLV
                        cycles = 2;
                        IMPLIED();
                        CLV();
                        break;

            case 0xB9:  //LDA
                        cycles = 4;
                        ABSOLUTE_Y();
                        LDA();
                        break;

            case 0xBA:  //TSX
                        cycles = 2;
                        IMPLIED();
                        TSX();
                        break;

            case 0xBC:  //LDY
                        cycles = 4;
                        ABSOLUTE_X();
                        LDY();
                        break;

            case 0xBD:  //LDA
                        cycles = 4;
                        ABSOLUTE_X();
                        LDA();
                        break;

            case 0xBE:  //LDX
                        cycles = 4;
                        ABSOLUTE_Y();
                        LDX();
                        break;

            case 0xC0:  //CPY
                        cycles = 2;
                        IMMEDIATE();
                        CPY();
                        break;

            case 0xC1:  //CMP
                        cycles = 6;
                        INDIRECT_X();
                        CMP();
                        break;

            case 0xC4:  //CPY
                        cycles = 3;
                        ZEROPAGE();
                        CPY();
                        break;

            case 0xC5:  //CMP
                        cycles = 3;
                        ZEROPAGE();
                        CMP();
                        break;

            case 0xC6:  //DEC
                        cycles = 5;
                        ZEROPAGE();
                        DEC();
                        break;

            case 0xC8:  //INY
                        cycles = 2;
                        IMPLIED();
                        INY();
                        break;

            case 0xC9:  //CMP
                        cycles = 2;
                        IMMEDIATE();
                        CMP();
                        break;

            case 0xCA:  //DEX
                        cycles = 2;
                        IMPLIED();
                        DEX();
                        break;

            case 0xCC:  //CPY
                        cycles = 4;
                        ABSOLUTE();
                        CPY();
                        break;

            case 0xCD:  //CMP
                        cycles = 4;
                        ABSOLUTE();
                        CMP();
                        break;

            case 0xCE:  //DEC
                        cycles = 6;
                        ABSOLUTE();
                        DEC();
                        break;

            case 0xD0:  //BNE
                        cycles = 2;
                        RELATIVE();
                        BNE();
                        break;

            case 0xD1:  //CMP
                        cycles = 5;
                        INDIRECT_Y();
                        CMP();
                        break;

            case 0xD5:  //CMP
                        cycles = 4;
                        ZEROPAGE_X();
                        CMP();
                        break;

            case 0xD6:  //DEC
                        cycles = 6;
                        ZEROPAGE_X();
                        DEC();
                        break;

            case 0xD8:  //CLD
                        cycles = 2;
                        IMPLIED();
                        CLD();
                        break;

            case 0xD9:  //CMP
                        cycles = 4;
                        ABSOLUTE_Y();
                        CMP();
                        break;

            case 0xDD:  //CMP
                        cycles = 4;
                        ABSOLUTE_X();
                        CMP();
                        break;

            case 0xDE:  //DEC
                        ABSOLUTE_X();
                        cycles = 7;
                        DEC();
                        break;

            case 0xE0:  //CPX
                        cycles = 2;
                        IMMEDIATE();
                        CPX();
                        break;

            case 0xE1:  //SBC
                        cycles = 6;
                        INDIRECT_X();
                        SBC();
                        break;

            case 0xE4:  //CPX
                        cycles = 3;
                        ZEROPAGE();
                        CPX();
                        break;

            case 0xE5:  //SBC
                        cycles = 3;
                        ZEROPAGE();
                        SBC();
                        break;

            case 0xE6:  //INC
                        cycles = 5;
                        ZEROPAGE();
                        INC();
                        break;

            case 0xE8:  //INX
                        cycles = 2;
                        IMPLIED();
                        INX();
                        break;

            case 0xE9:  //SBC
                        cycles = 2;
                        IMMEDIATE();
                        SBC();
                        break;

            case 0xEA:  //NOP
                        cycles = 2;
                        IMPLIED();
                        NOP();
                        break;

            case 0xEC:  //CPX
                        cycles = 4;
                        ABSOLUTE();
                        CPX();
                        break;

            case 0xED:  //SBC
                        cycles = 4;
                        ABSOLUTE();
                        SBC();
                        break;

            case 0xEE:  //INC
                        cycles = 6;
                        ABSOLUTE();
                        INC();
                        break;

            case 0xF0:  //BEQ
                        cycles = 2;
                        RELATIVE();
                        BEQ();
                        break;

            case 0xF1:  //SBC
                        cycles = 5;
                        INDIRECT_Y();
                        SBC();
                        break;

            case 0xF5:  //SBC
                        cycles = 4;
                        ZEROPAGE_X();
                        SBC();
                        break;

            case 0xF6:  //INC
                        cycles = 6;
                        ZEROPAGE_X();
                        INC();
                        break;

            case 0xF8:  //SED
                        cycles = 2;
                        IMPLIED();
                        SED();
                        break;

            case 0xF9:  //SBC
                        cycles = 4;
                        ABSOLUTE_Y();
                        SBC();
                        break;

            case 0xFD:  //SBC
                        cycles = 4;
                        ABSOLUTE_X();
                        SBC();
                        break;

            case 0xFE:  //INC
                        ABSOLUTE_X();
                        cycles = 7;
                        INC();
                        break;
            
            default: break; //illegal opcode
        }
    }

    void
    Cpu::run()
    {
        if (cycles <= 0) {

            execute_opcode();

            #ifdef DEBUG_INFO
                std::cout << "---------------------" << std::endl;
                printf("REGISTER A = %2X\n", this->A);
                printf("REGISTER Y = %2X\n", this->Y);
                printf("REGISTER X = %2X\n", this->X);
                printf("REGISTER SP = %2X\n", this->SP);
                printf("REGISTER PC = %4X\n", this->PC);
                printf("REGISTER SR = %2X\n", this->SR);
            #endif
        }
        else
            cycles--;
    
    }

    void
    Cpu::load(std::vector<uint8_t> &instr, uint16_t addr)
    {
        uint16_t index = addr;
        for (uint8_t i : instr) {
            mem_write(index, i);
            index++;
        }
    }

    bool
    Cpu::is_BRK()
    {
        return (opcode == 0);
    }
}
