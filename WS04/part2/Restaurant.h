#ifndef SENECA_RESTAURANT_H
#define SENECA_RESTAURANT_H
#include <vector>
#include <chrono>
#include <iostream>
#include <string>
#include "Reservation.h"
namespace seneca
{
    class Restaurant
    {
        Reservation **reservations{nullptr};
        size_t nums{}; // each element of the array points to an object of type Reservation)
    public:
        Restaurant(const Reservation *reservations[], size_t cnt);
        size_t size() const;

        ~Restaurant();
        void deallocated();
        // copy constructor
        Restaurant(const Restaurant &other);
        // copy operator
        Restaurant &operator=(const Restaurant &other);
        // move constructor
        Restaurant(Restaurant &&other);
        // move operator
        Restaurant &operator=(Restaurant &&other);
        // helper function
        friend std::ostream &operator<<(std::ostream &os, const Restaurant &r);
    };
}
#endif
