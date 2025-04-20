#pragma once
#include <memory>
#include <string>
#include <unordered_map>

#include "iresource.h"

class resource_manager
{
public:
    resource_manager();

    void load_surface(const std::string& path);
    void load_font(const std::string& path);
    iresource* get_resource(const std::string& path);

private:
    static bool resource_file_exists(const std::string& path);

    std::unordered_map<std::string, std::shared_ptr<iresource>> m_resource_map;
};

extern resource_manager g_resource_manager;