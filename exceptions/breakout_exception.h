#ifndef BREAKOUT_EXCEPTION_H
#define BREAKOUT_EXCEPTION_H
#include <exception>
#include <string>


class breakout_exception : public std::exception
{
public:
    explicit breakout_exception(const std::string& message);
    ~breakout_exception() noexcept override = default;
    [[nodiscard]] const char* what() const noexcept override;

private:
    std::string _message;
};


#endif //BREAKOUT_EXCEPTION_H
