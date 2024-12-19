#include "register.hpp"

Register::Register(const char *name, u8 initial_value)
    : name{name}, data{initial_value} {}

void Register::set_bit(u8 pos, bool bit)
{
    if (bit)
    {
        data |= (1 << (pos - 1));
    }
    else
    {
        data &= ~(1 << (pos - 1));
    }
}

void Register::set_data(u8 data)
{
    this->data = data;
}

void Register::reset()
{
    data = 0;
}

std::vector<u8> Register::get_bits() const noexcept
{
    std::vector<u8> bits;

    for (int i = 0; i < 8; i++)
    {
        bits.push_back(data & (1 << i));
    }

    return bits;
}