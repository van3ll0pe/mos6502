#include "cpu.hpp"

namespace mos6502
{
    void
    Cpu::push_8b(uint8_t data)
    {
        mem_write((STACK | this->SP--), data);
    }

    void
    Cpu::push_16b(uint16_t data)
    {
        mem_write((STACK | this->SP--), ((data & 0xFF00) >> 8));
        mem_write((STACK | this->SP--), (data & 0xFF));
    }

    uint8_t
    Cpu::pull_8b()
    {
        return mem_read((STACK | ++this->SP));
    }

    uint16_t
    Cpu::pull_16b()
    {
        uint16_t data = mem_read((STACK | ++this->SP));
        data |= (mem_read((STACK | ++this->SP)) << 8);

        return data;
    }
}