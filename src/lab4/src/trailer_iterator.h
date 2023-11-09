#pragma once
#include "trailer_strategy.h"

#include <vector>

// Iterator Pattern
class TrailerIterator {
public:
    virtual bool hasNext() const = 0;
    virtual TrailerStrategy* next() = 0;
    virtual ~TrailerIterator() = default;
};

class TruckTrailerIterator : public TrailerIterator {
private:
    std::vector<TrailerStrategy*> trailers;
    size_t current;

public:
    TruckTrailerIterator(std::vector<TrailerStrategy*> trailers)
            : trailers(trailers)
            , current(0) {}

    bool hasNext() const override {
        return current < trailers.size();
    }

    TrailerStrategy* next() override {
        if (hasNext()) {
            return trailers[current++];
        }
        return nullptr;
    }
};
