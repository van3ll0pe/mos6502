#include "cpu.hpp"

namespace mos6502
{
    void
    Cpu::fetch_opcode()
    {
        this->opcode = mem_read(this->PC++);
    }
    
    void
    Cpu::fetch_value()
    {
        this->value_address = mem_read(this->address);
    }

    void 
    Cpu::IMPLIED()
    {
        return;
    }

    void
    Cpu::IMMEDIATE()
    {
        this->address = this->PC++;
    }

    void
    Cpu::ABSOLUTE()
    {
        this->address = mem_read(this->PC++);
        this->address |= (mem_read(this->PC++) << 8);
    }

    void
    Cpu::ZEROPAGE()
    {
        this->address = mem_read(this->PC++);
    }

    void
    Cpu::ABSOLUTE_X()
    {
        ABSOLUTE();
        if (((this->address & 0xFF) + this->X) & 0x100)
            cycles++;

        this->address += this->X;
    }

    void
    Cpu::ABSOLUTE_Y()
    {
        ABSOLUTE();

        if (((this->address & 0xFF) + this->Y) & 0x100)
            cycles++;
            
        this->address += this->Y;
    }

    void
    Cpu::ZEROPAGE_X()
    {
        this->address = mem_read(this->PC++) + this->X;
        this->address &= 0x00FF;
    }

    void
    Cpu::ZEROPAGE_Y()
    {
        this->address = mem_read(this->PC++) + this->Y;
        this->address &= 0x00FF;
    }

    void
    Cpu::INDIRECT()
    {
        uint16_t ptr = mem_read(this->PC++);
        ptr |= (mem_read(this->PC++) << 8);

        this->address = mem_read(ptr);
        this->address |= (mem_read(ptr + 1) << 8);
    }

    void
    Cpu::INDIRECT_X()
    {
        uint16_t ptr = mem_read(this->PC++) + X;
        ptr &= 0x00FF;

        this->address = mem_read(ptr);
        this->address |= mem_read(ptr + 1);
    }

    void
    Cpu::INDIRECT_Y()
    {
        uint16_t ptr = mem_read(this->PC++);

        this->address = mem_read(ptr);
        this->address |= (mem_read(ptr + 1) << 8);
        this->address += this->Y;
    }

    void
    Cpu::RELATIVE()
    {
        uint8_t rel = mem_read(this->PC++);
        uint16_t rel_address = 0x0000 | rel;

        if (rel & 0x80) //if rel is negative
            rel_address = 0xFF00 | rel;
        
        this->address = this->PC + rel_address;
    }
}