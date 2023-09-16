#pragma once

#include <string>

class Vehicle {
public:
    Vehicle(const std::string& name);
    virtual void start() = 0;
    virtual void stop() = 0;
    std::string get_name();
    bool is_started();

protected:
    std::string name;
    bool started = false;
};
