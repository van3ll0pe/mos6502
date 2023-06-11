#include "cpu.hpp"


namespace mos6502
{
    void
    Cpu::LDA()
    {
        fetch_value();

        this->A = this->value_address;

        check_flag(NEGATIVE_FLAG, (this->A & 0x80));
        check_flag(ZERO_FLAG, (this->A == 0));
    }

    void
    Cpu::LDX()
    {
        fetch_value();

        this->X = this->value_address;

        check_flag(NEGATIVE_FLAG, (this->X & 0x80));
        check_flag(ZERO_FLAG, (this->X == 0));
    }

    void
    Cpu::LDY()
    {
        fetch_value();

        this->Y = this->value_address;

        check_flag(NEGATIVE_FLAG, (this->Y & 0x80));
        check_flag(ZERO_FLAG, (this->Y == 0));
    }

    void
    Cpu::STA()
    {
        mem_write(this->address, this->A);
    }

    void
    Cpu::STX()
    {
        mem_write(this->address, this->X);
    }

    void
    Cpu::STY()
    {
        mem_write(this->address, this->Y);
    }

    void
    Cpu::TAX()
    {
        this->X = this->A;

        check_flag(NEGATIVE_FLAG, (this->X & 0x80));
        check_flag(ZERO_FLAG, (this->X == 0));
    }

    void
    Cpu::TAY()
    {
        this->Y = this->A;

        check_flag(NEGATIVE_FLAG, (this->Y & 0x80));
        check_flag(ZERO_FLAG, (this->Y == 0));
    }

    void
    Cpu::TSX()
    {
        this->X = this->SP;

        check_flag(NEGATIVE_FLAG, (this->X & 0x80));
        check_flag(ZERO_FLAG, (this->X == 0));
    }

    void
    Cpu::TXA()
    {
        this->A = this->X;

        check_flag(NEGATIVE_FLAG, (this->A & 0x80));
        check_flag(ZERO_FLAG, (this->A == 0));
    }

    void
    Cpu::TXS()
    {
        this->SP = this->X;
    }

    void
    Cpu::TYA()
    {
        this->A = this->Y;

        check_flag(NEGATIVE_FLAG, (this->A & 0x80));
        check_flag(ZERO_FLAG, (this->A == 0));
    }
}