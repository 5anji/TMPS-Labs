#pragma once

// Bridge: TruckPlatform (Abstract bridge for Truck platforms)
class TruckPlatform {
public:
    virtual void deliver() const = 0;
    virtual ~TruckPlatform() = default;
};
