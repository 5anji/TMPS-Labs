#pragma once

// Component: Truck
class Truck {
public:
    virtual void deliver() const = 0;
    virtual ~Truck() = default;
};
