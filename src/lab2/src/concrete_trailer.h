#pragma once

#include "trailer.h"

#include <fmt/format.h>
#include <memory>

class ConcreteTrailer : public Trailer {
public:
    class ConcreteBuilder : public Builder {
    public:
        ConcreteBuilder(const std::string& n)
                : Builder(n) {}

        std::unique_ptr<Trailer> build() override {
            auto trailer = std::make_unique<ConcreteTrailer>();
            trailer->name = name;
            return trailer;
        }
    };

    void attach() override {
        fmt::println("Concrete Trailer with name {} is attached.", name);
    }

private:
    std::string name;
};
