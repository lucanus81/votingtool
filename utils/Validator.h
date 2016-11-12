#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <experimental/string_view>

template <typename T>
struct validator
{
    bool validate() const
    {
        const auto* ptr = static_cast<const T*>(this);
        return ptr->real_validate();
    }

    std::string why() const
    {
        std::string error{"There's something wrong: "};

        const auto* ptr = static_cast<const T*>(this);
        return error += ptr->real_why();
    }
};

struct hostname_validator : validator<hostname_validator>
{
    hostname_validator(const std::experimental::string_view& hostname)
    : hostname_{hostname}
    {}

    bool real_validate() const { return true; }
    std::string real_why() const { return {}; }

private:
    const std::experimental::string_view hostname_;
};

struct port_validator : validator<port_validator>
{
    port_validator(uint16_t port) 
    : port_{port}
    {}

    bool real_validate() const { return port_ >= 1000; }
    std::string real_why() const { return {"Port until 1000 are reserved. Use a value 1000<X<=65535."}; }

private:
    uint16_t port_{0};
};


#endif // VALIDATOR_H
