#include "cpu.hpp"


namespace mos6502
{
    void
    Cpu::CLC()
    {
        clear_flag(CARRY_FLAG);
    }

    void
    Cpu::CLD()
    {
        clear_flag(DECIMAL_FLAG);
    }

    void
    Cpu::CLI()
    {
        clear_flag(INTERRUPT_FLAG);
    }

    void
    Cpu::CLV()
    {
        clear_flag(OVERFLOW_FLAG);
    }
    
    void
    Cpu::SEC()
    {
        set_flag(CARRY_FLAG);
    }

    void
    Cpu::SED()
    {
        set_flag(DECIMAL_FLAG);
    }

    void
    Cpu::SEI()
    {
        set_flag(INTERRUPT_FLAG);
    }
}