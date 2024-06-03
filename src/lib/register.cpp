#include <register.hpp>
#include <pch.hpp>

Register::Register(unsigned char initial_value, const char *name)
    : data(initial_value), name(name)
{
}

void Register::set_bit(bool bit, int pos)
{
    pos--;
    unsigned char d = bit == true ? 1 << pos : ~(1 << pos);
    if (bit == true)
        data = data | d;
    else
        data = data & d;
}

std::string Register::get_bitdata() const
{
    char bits[8];
    for (int i = 0; i < 8; i++)
    {
        unsigned char b = data & (1 << i);
        bits[7 - i] = b ? '1' : '0';
    }
    char dummy[9];
    memcpy(dummy, bits, 8);
    dummy[8] = '\0';
    return std::string(dummy);
}