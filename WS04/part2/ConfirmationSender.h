/*
    Name: Hao Han Kao
    Seneca Email: hhao@myseneca.ca
    Seneca Student ID: 151604220
    Date: 6/9

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_CONFIRMATIONSENDER_H
#define SENECA_CONFIRMATIONSENDER_H
#include "Reservation.h"
#include <chrono>
#include <iostream>
#include <string>

namespace seneca
{
    class ConfirmationSender
    {
        const Reservation **reservations{nullptr};
        size_t count{};

    public:
        ConfirmationSender() = default;
        // delete
        ~ConfirmationSender();
        // copy consturctor
        ConfirmationSender(const ConfirmationSender &other);
        // copy operator
        ConfirmationSender &operator=(const ConfirmationSender &other);
        // move consturctor

        ConfirmationSender(ConfirmationSender &&other);
        // move operator
        ConfirmationSender &operator=(ConfirmationSender &&other);
        //++
        ConfirmationSender &operator+=(const Reservation &res);
        //--
        ConfirmationSender &operator-=(const Reservation &res);
        // helper
        friend std::ostream &operator<<(std::ostream &os, const ConfirmationSender &c);
    };

}
#endif
// Aggregation
// add any special members that are necessary to manage the resource (the resource is an array of pointers; your class must manage this array,
//  but the objects at the addresses stored in the array are managed outside this class)

// move consturctor -> && means rvalue reference
