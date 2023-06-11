#include "cpu.hpp"

namespace mos6502
{
    void
    Cpu::CMP()
    {
        fetch_value();

        uint8_t res = this->A - this->value_address;

        check_flag(NEGATIVE_FLAG, (res & 0x80));
        check_flag(ZERO_FLAG, (res == 0));
        check_flag(CARRY_FLAG, ((this->A - this->value_address) & 0x100));
    }

    void
    Cpu::CPX()
    {
        fetch_value();

        uint8_t res = this->X - this->value_address;

        check_flag(NEGATIVE_FLAG, (res & 0x80));
        check_flag(ZERO_FLAG, (res == 0));
        check_flag(CARRY_FLAG, ((this->X - this->value_address) & 0x100));
    }

    void
    Cpu::CPY()
    {
        fetch_value();

        uint8_t res = this->Y - this->value_address;

        check_flag(NEGATIVE_FLAG, (res & 0x80));
        check_flag(ZERO_FLAG, (res == 0));
        check_flag(CARRY_FLAG, ((this->Y - this->value_address) & 0x100));
    }
}