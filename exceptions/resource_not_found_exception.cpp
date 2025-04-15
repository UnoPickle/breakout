#include "resource_not_found_exception.h"

resource_not_found_exception::resource_not_found_exception(const std::string& resource_path) : breakout_exception(
    "[ resource_not_found_exception ]: could not locate \"" + resource_path + "\"")
{
}
