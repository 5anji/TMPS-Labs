#pragma once
#include "trailer_iterator.h"
#include "truck_observer.h"

// Context (Truck) using Strategy and Iterator
class Truck {
private:
    TrailerIterator* trailerIterator;
    std::vector<TruckObserver*> observers;

public:
    Truck(TrailerIterator* iterator)
            : trailerIterator(iterator) {}

    void attachObserver(TruckObserver* observer) {
        observers.push_back(observer);
    }

    void notifyObservers() const {
        for (const auto& observer : observers) {
            observer->update(trailerIterator->next());
        }
    }

    void transportGoods() {
        while (trailerIterator->hasNext()) {
            notifyObservers();
        }
    }
};
