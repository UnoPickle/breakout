

#include "iresource.h"

iresource::iresource(const resource_type type) : m_type(type){
}

resource_type iresource::get_type() const {
    return m_type;
}
