#pragma once
#include "breakout_exception.h"

class resource_not_found_exception : public breakout_exception
{
public:
    explicit resource_not_found_exception(const std::string& resource_path);
};
