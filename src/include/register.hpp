#pragma once
#include <string>

class Register
{
private:
    unsigned char data;
    const char *name;

public:
    Register(unsigned char intial_value, const char *name);

    void set_bit(bool bit, int pos);
    std::string get_bitdata() const;

    inline unsigned char get_data() const { return data; }
    inline void clear() { data = 0; }
};