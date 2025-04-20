#pragma once

enum class resource_type {
    IMAGE,
    AUDIO,
    FONT
};

class iresource {
public:
    explicit iresource(const resource_type type);

    [[nodiscard]] resource_type get_type() const;


private:
    resource_type m_type;
};
