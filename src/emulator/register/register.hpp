#pragma once
#include <emulator/config.hpp>

class Register
{
private:
    u8 data;
    const char *name;

public:
    Register(const char *name, u8 initial_value = 0);

    void set_bit(u8 pos, bool bit);
    void set_data(u8 data);
    void reset();
    std::vector<u8> get_bits() const noexcept;

    inline u8 get_data() const noexcept { return data; }
    inline const char *get_name() const noexcept { return name; }
};