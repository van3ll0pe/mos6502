#include "cpu.hpp"

namespace mos6502
{
    void
    Cpu::BRK()
    {
        this->PC++; //IMPLIED doen't increment PC, but BRK use a extra byte spacing, so we increment to push PC on the next valid opcode
        push_16b(this->PC);

        push_8b(this->SR | BREAK_FLAG | UNUSED_FLAG);
        set_flag(INTERRUPT_FLAG);

        this->PC = (mem_read(IRQ_VECTOR_H) << 8) | mem_read(IRQ_VECTOR_L);
    }

    void
    Cpu::JMP()
    {
        this->PC = this->address;
    }

    void
    Cpu::JSR()
    {
        this->PC--;
        push_16b(this->PC);

        this->PC = this->address;
    }

    void
    Cpu::NOP()
    {
        return;
    }

    void
    Cpu::RTI()
    {
        this->SR = pull_8b();
        clear_flag(BREAK_FLAG);
        clear_flag(UNUSED_FLAG);

        this->PC = pull_16b();
    }

    void
    Cpu::RTS()
    {
        this->PC = pull_16b();
        this->PC++;
    }
}
