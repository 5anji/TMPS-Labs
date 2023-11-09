#pragma once
#include <fmt/format.h>

// Strategy Pattern
class TrailerStrategy {
public:
    virtual void transport() const = 0;
};

class SmallTrailerStrategy : public TrailerStrategy {
public:
    void transport() const override {
        fmt::println("Small trailer is transporting goods.");
    }
};

class LargeTrailerStrategy : public TrailerStrategy {
public:
    void transport() const override {
        fmt::println("Large trailer is transporting goods.");
    }
};
