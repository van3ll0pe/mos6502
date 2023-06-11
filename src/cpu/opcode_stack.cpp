#include "cpu.hpp"


namespace mos6502
{
    void
    Cpu::PHA()
    {
        push_8b(this->A);
    }

    void
    Cpu::PHP()
    {
        push_8b(this->SR | BREAK_FLAG | UNUSED_FLAG);
    }

    void
    Cpu::PLA()
    {
        this->A = pull_8b();

        check_flag(NEGATIVE_FLAG, (this->A & 0x80));
        check_flag(ZERO_FLAG, (this->A == 0));
    }

    void
    Cpu::PLP()
    {
        this->SR = pull_8b();
        clear_flag(BREAK_FLAG);
        clear_flag(UNUSED_FLAG);
    }
}