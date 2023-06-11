#include "cpu.hpp"

namespace mos6502
{
    void
    Cpu::BCC()
    {
        if (get_flag(CARRY_FLAG) == 0) {
            cycles++;

            if ((this->address & 0xFF00) != (this->PC & 0xFF00))
                cycles++;

            this->PC = this->address;


        }
    }

    void
    Cpu::BCS()
    {
        if (get_flag(CARRY_FLAG) == 1) {
            cycles++;

            if ((this->address & 0xFF00) != (this->PC & 0xFF00))
                cycles++;

            this->PC = this->address;
        }
    }

    void
    Cpu::BEQ()
    {
        if (get_flag(ZERO_FLAG) == 1) {
            cycles++;

            if ((this->address & 0xFF00) != (this->PC & 0xFF00))
                cycles++;

            this->PC = this->address;
        }
    }

    void
    Cpu::BMI()
    {
        if (get_flag(NEGATIVE_FLAG) == 1) {
            cycles++;

            if ((this->address & 0xFF00) != (this->PC & 0xFF00))
                cycles++;

            this->PC = this->address;
        }
    }

    void
    Cpu::BNE()
    {
        if (get_flag(ZERO_FLAG) == 0) {
            cycles++;

            if ((this->address & 0xFF00) != (this->PC & 0xFF00))
                cycles++;

            this->PC = this->address;
        }
    }

    void
    Cpu::BPL()
    {
        if (get_flag(NEGATIVE_FLAG) == 0) {
            cycles++;

            if ((this->address & 0xFF00) != (this->PC & 0xFF00))
                cycles++;

            this->PC = this->address;
        }
    }

    void
    Cpu::BVC()
    {
        if (get_flag(OVERFLOW_FLAG) == 0) {
            cycles++;

            if ((this->address & 0xFF00) != (this->PC & 0xFF00))
                cycles++;

            this->PC = this->address;
        }
    }

    void
    Cpu::BVS()
    {
        if (get_flag(OVERFLOW_FLAG) == 1) {
            cycles++;

            if ((this->address & 0xFF00) != (this->PC & 0xFF00))
                cycles++;
                
            this->PC = this->address;
        }
    }


    


}