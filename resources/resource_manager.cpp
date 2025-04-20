#include "resource_manager.h"
#include <fstream>

#include "font_resource.h"
#include "image_resource.h"
#include "../exceptions/resource_not_found_exception.h"

resource_manager g_resource_manager;

resource_manager::resource_manager()
{

}

void resource_manager::load_surface(const std::string& path)
{
    if (!resource_file_exists(path))
    {
        throw resource_not_found_exception(path);
    }

    m_resource_map.emplace(path, std::make_shared<image_resource>(path));
}

void resource_manager::load_font(const std::string& path)
{
    if (!resource_file_exists(path))
    {
        throw resource_not_found_exception(path);
    }

    m_resource_map.emplace(path, std::make_shared<font_resource>(path));
}

iresource* resource_manager::get_resource(const std::string& path)
{
    const auto it = m_resource_map.find(path);
    if (it == m_resource_map.end())
    {
        return nullptr;
    }

    return it->second.get();
}

bool resource_manager::resource_file_exists(const std::string& path)
{
    std::ifstream file(path.c_str());
    if (!file.good())
    {
        return false;
    }

    file.close();
    return true;
}
