
/*
    Name: Hao Han Kao
    Seneca Email: hhao@myseneca.ca
    Seneca Student ID: 151604220
    Date: 6/9

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
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
