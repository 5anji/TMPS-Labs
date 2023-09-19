#pragma once

#include <fmt/format.h>
#include <memory>

class Trailer {
public:
    virtual void attach() {
        fmt::println("Trailer is attached.");
    };

    class Builder {
    protected:
        std::string name;

    public:
        Builder(const std::string& n)
                : name(n) {}

        virtual std::unique_ptr<Trailer> build() = 0;
    };
};
