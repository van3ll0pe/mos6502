#include "cpu.hpp"

namespace mos6502
{
    uint8_t
    Cpu::mem_read(uint16_t address)
    {
        return this->memory[address];
    }

    void
    Cpu::mem_write(uint16_t address, uint8_t value)
    {
        this->memory[address] = value;
    }
}