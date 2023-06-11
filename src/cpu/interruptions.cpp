#include "cpu.hpp"

namespace mos6502
{
    void
    Cpu::IRQ()
    {
        if (get_flag(INTERRUPT_FLAG) == 1) return;

        push_8b(this->SR | UNUSED_FLAG & (~BREAK_FLAG)); //PUT on the stack the SR register and the unused bit to 1 and the break flag to 0 without modifying the SR register
        set_flag(INTERRUPT_FLAG);

        push_16b(this->PC);

        this->PC = (mem_read(IRQ_VECTOR_H) << 8) | mem_read(IRQ_VECTOR_L);
        cycles = 7;
    }

    void
    Cpu::NMI()
    {
        push_8b(this->SR | UNUSED_FLAG & (~BREAK_FLAG));
        set_flag(INTERRUPT_FLAG);

        push_16b(this->PC);

        this->PC = (mem_read(NMI_VECTOR_H) << 8) | mem_read(NMI_VECTOR_L);
        cycles = 8;
    }

    void
    Cpu::RESET()
    {
        this->A = 0;
        this->X = 0;
        this->Y = 0;
        this->SR = UNUSED_FLAG;
        this->SP = 0xFD;

        this->PC = (mem_read(RST_VECTOR_H) << 8) | mem_read(RST_VECTOR_L);
        cycles = 8;
    }

    void
    Cpu::set_NMI_VECTOR(uint16_t value)
    {
        mem_write(NMI_VECTOR_L, (value & 0x00FF));
        mem_write(NMI_VECTOR_H, (value & 0xFF00) >> 8);
    }

    void
    Cpu::set_IRQ_VECTOR(uint16_t value)
    {
        mem_write(IRQ_VECTOR_L, (value & 0X00FF));
        mem_write(IRQ_VECTOR_H, (value & 0XFF00) >> 8);
    }

    void
    Cpu::set_RESET_VECTOR(uint16_t value)
    {
        mem_write(RST_VECTOR_L, (value & 0x00FF));
        mem_write(RST_VECTOR_H, (value & 0xFF00) >> 8);

        this->PC = (mem_read(RST_VECTOR_H) << 8) | mem_read(RST_VECTOR_L); 
    }
}