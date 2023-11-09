#include "trailer_iterator.h"
#include "trailer_strategy.h"
#include "truck.h"
#include "truck_observer.h"

int main() {
    // Create trailers with different strategies
    SmallTrailerStrategy smallTrailer;
    LargeTrailerStrategy largeTrailer;

    // Create iterator with trailers
    std::vector<TrailerStrategy*> trailers = {&smallTrailer, &largeTrailer};
    TruckTrailerIterator truckIterator(trailers);

    // Create observers
    TruckDriverObserver driverObserver;

    // Create truck with iterator
    Truck truck(&truckIterator);
    truck.attachObserver(&driverObserver);

    // Transport goods
    truck.transportGoods();

    return 0;
}
