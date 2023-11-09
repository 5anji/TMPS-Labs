# Topic: *Behavioral Design Patterns*

## Author: *Gitlan Gabriel, FAF-213*

------

## Objectives

&ensp; &ensp; __1. Study and understand the Behavioral Design Patterns.__

&ensp; &ensp; __2. As a continuation of the previous laboratory work, think about what communication between software entities might be involed in your system.__

&ensp; &ensp; __3. Create a new Project or add some additional functionalities using behavioral design patterns.__

## Theoretical background

&ensp; &ensp; Behavioral design patterns are a category of design patterns that focus on the interaction and communication between objects and classes. They provide a way to organize the behavior of objects in a way that is both flexible and reusable, while separating the responsibilities of objects from the specific implementation details. Behavioral design patterns address common problems encountered in object behavior, such as how to define interactions between objects, how to control the flow of messages between objects, or how to define algorithms and policies that can be reused across different objects and classes.

&ensp; &ensp; Some examples from this category of design patterns are:

* Chain of Responsibility
* Command
* Interpreter
* Iterator
* Mediator
* Observer
* Strategy

## Implementation

In this lab I tried to implement Strategy, Iterator, Observer design patterns into a single C++ program. The theme is also about trucks and trailers, but the functionality remains very primitive, to maintain the visibility of the patterns. So:

Strategy pattern is implemented inside this class:

```c++
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

```

Iterator pattern is the following:

```c++
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
```

And the final one. Observer:

```c++
class TruckObserver {
public:
    virtual void update(const TrailerStrategy* trailer) const = 0;
    virtual ~TruckObserver() = default;
};

class TruckDriverObserver : public TruckObserver {
public:
    void update(const TrailerStrategy* trailer) const override {
        fmt::print("Truck driver received update: ");
        trailer->transport();
    }
};

```

A helper class that unifies Strategy and Iterator:

```c++
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
```

main():

```c++
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

```

Output:

```txt
Truck driver received update: Small trailer is transporting goods.
Truck driver received update: Large trailer is transporting goods.
```

## Conclusion

### Strategy Pattern

* __Purpose:__ The Strategy pattern defines a family of algorithms, encapsulates each algorithm, and makes them interchangeable. It lets the client vary the algorithm independently from the clients that use it.

* __In the Program:__ The `TrailerStrategy` is the strategy interface, and `SmallTrailerStrategy` and `LargeTrailerStrategy` are concrete implementations. The `Truck` class can switch between different trailer strategies.

### Iterator Pattern

* __Purpose:__ The Iterator pattern provides a way to access the elements of an aggregate object sequentially without exposing its underlying representation.

* __In the Program:__ The `TrailerIterator` is the iterator interface, and `TruckTrailerIterator` is a concrete implementation that iterates through the trailers. It allows the `Truck` class to traverse its trailers without exposing their internal structure.

### Observer Pattern

* __Purpose:__ The Observer pattern defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

* __In the Program:__ The `TruckObserver` is the observer interface, and `TruckDriverObserver` is a concrete implementation. The `Truck` class maintains a list of observers (`TruckObserver`) and notifies them when transporting goods. The truck driver is an observer that receives updates on each trailer's transportation.

**Conclusion:**

* The Strategy pattern allows the program to define a family of trailer algorithms and switch between them seamlessly.
* The Iterator pattern simplifies the process of traversing the trailers in the truck without exposing the details of their implementation.
* The Observer pattern enables the truck to notify observers (like the truck driver) about the state changes (trailer transportation) without coupling the truck and the observers tightly.
