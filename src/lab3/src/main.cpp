#include "trailers/large_trailer.h"
#include "trailers/small_trailer.h"
#include "trailers/trailer.h"
#include "truck_platforms/large_truck_platform.h"
#include "truck_platforms/small_truck_platform.h"
#include "truck_platforms/truck_platform.h"
#include "truck_with_trailer.h"
#include "trucks/extended_truck.h"
#include "trucks/large_truck.h"
#include "trucks/premium_truck.h"
#include "trucks/small_truck.h"
#include "trucks/truck.h"
#include "trucks/truck_fleet.h"

#include <memory>

int main() {
    // Creating instances of trucks and trailers
    auto smallTruck = std::make_shared<SmallTruck>();
    auto largeTruck = std::make_shared<LargeTruck>();
    auto smallTrailer = std::make_shared<SmallTrailer>();
    auto largeTrailer = std::make_shared<LargeTrailer>();

    // Using Adapter to combine Truck and Trailer
    auto truckWithTrailer = std::make_shared<TruckWithTrailer>(smallTruck, largeTrailer);

    // Using Bridge to provide different Truck platforms
    auto smallTruckPlatform = std::make_shared<SmallTruckPlatform>();
    auto largeTruckPlatform = std::make_shared<LargeTruckPlatform>();
    auto extendedTruck = std::make_shared<ExtendedTruck>(smallTruckPlatform);

    // Using Composite to manage a fleet of trucks
    auto truckFleet = std::make_shared<TruckFleet>();
    truckFleet->add_truck(smallTruck);
    truckFleet->add_truck(largeTruck);

    // Using Decorator to add premium features to a Truck
    auto premiumTruck = std::make_shared<PremiumTruck>(largeTruck);

    // Delivering goods using various trucks and combinations
    smallTruck->deliver();
    largeTruck->deliver();
    smallTrailer->attach();
    largeTrailer->attach();
    truckWithTrailer->deliver();
    smallTruckPlatform->deliver();
    largeTruckPlatform->deliver();
    extendedTruck->deliver();
    truckFleet->deliver();
    premiumTruck->deliver();

    return 0;
}
