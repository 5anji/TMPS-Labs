#pragma once

// Component: Trailer
class Trailer {
public:
    virtual void attach() const = 0;
    virtual ~Trailer() = default;
};
