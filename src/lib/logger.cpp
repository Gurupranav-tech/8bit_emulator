#include <logger.hpp>

void Log::init()
{
    spdlog::default_logger()->set_pattern("%^[%T] %n: %v%$");
}