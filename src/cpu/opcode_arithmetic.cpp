#include "cpu.hpp"

namespace mos6502
{
    void
    Cpu::ADC()
    {
        fetch_value();

        uint16_t res = this->A + this->value_address + get_flag(CARRY_FLAG);

        if (get_flag(DECIMAL_FLAG) == 0) { //if it's not a BCD addition

            check_flag(NEGATIVE_FLAG, (res & 0x80));
            check_flag(ZERO_FLAG, res == 0);
            check_flag(OVERFLOW_FLAG, ((this->A ^ res) & (this->value_address ^ res) & 0x80));
            check_flag(CARRY_FLAG, (res & 0x100));
        }
        else { //if it's a BCD addition
            if ((res & 0x0F) > 0x9)
                res += 0x6;
            
            if (res & 0xF0 > 0x90)
                res += 0x60;

            check_flag(NEGATIVE_FLAG, (res & 0x80));
            check_flag(ZERO_FLAG, (res == 0));
            check_flag(OVERFLOW_FLAG, ((this->A ^ res) & (this->value_address ^ res) & 0x80));
            check_flag(CARRY_FLAG, res > 0x99);
        }

        this->A = res & 0xFF;
    }

    void
    Cpu::AND()
    {
        fetch_value();

        this->A &= this->value_address;

        check_flag(NEGATIVE_FLAG, (this->A & 0X80));
        check_flag(ZERO_FLAG, (this->A == 0));
    }

    void
    Cpu::BIT()
    {
        fetch_value();

        check_flag(NEGATIVE_FLAG, (this->value_address & NEGATIVE_FLAG));
        check_flag(OVERFLOW_FLAG, (this->value_address & OVERFLOW_FLAG));

        check_flag(ZERO_FLAG, ((this->A & this->value_address) == 0));
    }

    void
    Cpu::DEC()
    {
        fetch_value();

        this->value_address--;

        check_flag(NEGATIVE_FLAG, (this->value_address & 0x80));
        check_flag(ZERO_FLAG, (this->value_address == 0));

        mem_write(this->address, this->value_address);
    }

    void
    Cpu::DEX()
    {
        this->X--;

        check_flag(NEGATIVE_FLAG, (this->X & 0x80));
        check_flag(ZERO_FLAG, (this->X == 0));
    }

    void
    Cpu::DEY()
    {
        this->Y--;

        check_flag(NEGATIVE_FLAG, (this->Y & 0x80));
        check_flag(ZERO_FLAG, (this->Y == 0));
    }

    void
    Cpu::EOR()
    {
        fetch_value();

        this->A ^= this->value_address;

        check_flag(NEGATIVE_FLAG, (this->A & 0x80));
        check_flag(ZERO_FLAG, (this->A == 0));
    }

    void
    Cpu::INC()
    {
        fetch_value();

        this->value_address++;

        check_flag(NEGATIVE_FLAG, (this->value_address & 0x80));
        check_flag(ZERO_FLAG, (this->value_address == 0));

        mem_write(this->address, this->value_address);
    }

    void
    Cpu::INX()
    {
        this->X++;

        check_flag(NEGATIVE_FLAG, (this->X & 0x80));
        check_flag(ZERO_FLAG, (this->X == 0));
    }
    
    void
    Cpu::INY()
    {
        this->Y++;

        check_flag(NEGATIVE_FLAG, (this->Y & 0x80));
        check_flag(ZERO_FLAG, (this->Y == 0));
    }

    void
    Cpu::ORA()
    {
        fetch_value();

        this->A |= this->value_address;

        check_flag(NEGATIVE_FLAG, (this->A & 0x80));
        check_flag(ZERO_FLAG, (this->A == 0));
    }

    void
    Cpu::SBC()
    {
        fetch_value();

        this->value_address = ~this->value_address;

        uint16_t res = this->A + this->value_address + get_flag(CARRY_FLAG);

        if (get_flag(DECIMAL_FLAG) == 0) { //sub
            check_flag(NEGATIVE_FLAG, (res & 0x80));
            check_flag(ZERO_FLAG, (res == 0));
            check_flag(OVERFLOW_FLAG, ((this->A ^ res) & (this->value_address ^ res) & 0x80));
            check_flag(CARRY_FLAG, (res & 0x100));
        }
        else { //BCD sub
            if (res & 0x0F > 0x9)
                res -= 0x6;
            
            if (res & 0xF0 > 0x90)
                res -= 0x60;
            
            check_flag(NEGATIVE_FLAG, (res & 0x80));
            check_flag(ZERO_FLAG, (res == 0));
            check_flag(OVERFLOW_FLAG, ((this->A ^ res) & (this->value_address ^ res) & 0x80));
            check_flag(CARRY_FLAG, (res & 0x100));
        }
    
        this->A = res;
    }

}