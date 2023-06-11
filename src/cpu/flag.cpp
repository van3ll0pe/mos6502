#include "cpu.hpp"

namespace mos6502
{
    uint8_t
    Cpu::get_flag(uint8_t FLAG)
    {
        return (this->SR & FLAG) ? 1 : 0;
    }

    void
    Cpu::set_flag(uint8_t FLAG)
    {
        this->SR |= FLAG;
    }

    void
    Cpu::clear_flag(uint8_t FLAG)
    {
        this->SR &= (~FLAG);
    }

    void
    Cpu::check_flag(uint8_t FLAG, bool condition)
    {
        if (condition)
            set_flag(FLAG);
        else
            clear_flag(FLAG);
    }
}