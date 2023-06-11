#include "cpu.hpp"

namespace mos6502
{
        void
    Cpu::ASL()
    {
       fetch_value();

        check_flag(CARRY_FLAG, (this->value_address & 0x80));

       this->value_address <<= 1;

       check_flag(NEGATIVE_FLAG, (this->value_address & 0x80));
       check_flag(ZERO_FLAG, (this->value_address == 0));

       mem_write(this->address, this->value_address);
    }

    void
    Cpu::ASL_A()
    {
        check_flag(CARRY_FLAG, (this->A & 0x80));

        this->A <<= 1;

        check_flag(NEGATIVE_FLAG, (this->A & 0x80));
        check_flag(ZERO_FLAG, (this->A == 0));
    }

    void
    Cpu::LSR()
    {
        fetch_value();

        check_flag(CARRY_FLAG, (this->value_address & 0x1));

        this->value_address >>= 1;

        clear_flag(NEGATIVE_FLAG); //O on negative flag
        check_flag(ZERO_FLAG, (this->value_address == 0));

        mem_write(this->address, this->value_address);
    }

    void
    Cpu::LSR_A()
    {
        check_flag(CARRY_FLAG, (this->A & 0x1));

        this->A >>= 1;

        clear_flag(NEGATIVE_FLAG);
        check_flag(ZERO_FLAG, (this->A == 0));
    }

    void
    Cpu::ROL()
    {
        fetch_value();

        uint8_t save_carry = get_flag(CARRY_FLAG);

        check_flag(CARRY_FLAG, (this->value_address & 0x80)); //put the 7bit in cARRY

        this->value_address <<= 1;
        this->value_address |= save_carry; //put the old value of carry into the 0bit of value_address

        check_flag(NEGATIVE_FLAG, (this->value_address & 0x80));
        check_flag(ZERO_FLAG, (this->value_address == 0));
    

        mem_write(this->address, this->value_address);
    }

    void
    Cpu::ROL_A()
    {
        uint8_t save_carry = get_flag(CARRY_FLAG);

        check_flag(CARRY_FLAG, (this->A & 0x80));

        this->A <<= 1;
        this->A |= save_carry;

        check_flag(NEGATIVE_FLAG, (this->A & 0x80));
        check_flag(ZERO_FLAG, (this->A == 0));
    }

    void
    Cpu::ROR()
    {
        fetch_value();

        uint8_t save_carry = get_flag(CARRY_FLAG);

        check_flag(CARRY_FLAG, (this->value_address & 0x1));

        this->value_address >>= 1;
        this->value_address |= (save_carry << 7);

        check_flag(NEGATIVE_FLAG, (this->value_address & 0x80));
        check_flag(ZERO_FLAG, (this->value_address == 0));

        mem_write(this->address, this->value_address);
    }

    void
    Cpu::ROR_A()
    {
        uint8_t save_carry = get_flag(CARRY_FLAG);

        check_flag(CARRY_FLAG, (this->A & 0x1));

        this->A >>= 1;
        this->A |= (save_carry << 7);

        check_flag(NEGATIVE_FLAG, (this->A & 0x80));
        check_flag(ZERO_FLAG, (this->A == 0));
    }
}