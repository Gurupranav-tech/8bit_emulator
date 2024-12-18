#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <functional>
#include <string_view>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <exception>
#include <thread>
#include <spdlog/spdlog.h>

using uint = unsigned int;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

#define INFO(...) spdlog::info(__VA_ARGS__)
#define WARN(...) spdlog::warn(__VA_ARGS__)
#define ERROR(...) spdlog::error(__VA_ARGS__)