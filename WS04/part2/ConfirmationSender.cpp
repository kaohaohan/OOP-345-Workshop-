/*
    Name: Hao Han Kao
    Seneca Email: hhao@myseneca.ca
    Seneca Student ID: 151604220
    Date: 6/9

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "ConfirmationSender.h"
#include <iostream>

namespace seneca
{
    ConfirmationSender::~ConfirmationSender()
    {
        // 不用刪掉裡面的reservation pointer
        delete[] reservations;
    }
    // copy operator
    ConfirmationSender &ConfirmationSender::operator=(const ConfirmationSender &other)
    {
        if (this != &other)
        {

            delete[] reservations;
            count = other.count;
            reservations = new const Reservation *[count];
            for (size_t i = 0; i < count; ++i)
            {
                reservations[i] = other.reservations[i]; // copy data // shallow copy!!!!!!!!! conConfirmationSenderfir class doenst have to manage this one
            }
        }

        return *this;
    }

    // copy constructor
    ConfirmationSender::ConfirmationSender(const ConfirmationSender &other)
    {
        *this = other;
    }
    // move constructor
    ConfirmationSender::ConfirmationSender(ConfirmationSender &&other)
    {
    }
    // move operator
    ConfirmationSender &ConfirmationSender::operator=(ConfirmationSender &&other)
    {
        if (this != &other)
        {
            delete[] reservations;
            count = other.count;
            reservations = other.reservations;
            other.reservations = nullptr;
            other.count = 0;
        }
        return *this;
    }
    // add
    ConfirmationSender &ConfirmationSender::operator+=(const Reservation &res)
    { // deal with the res has already has in reservations[i]; do nothing
        for (size_t i = 0; i < count; i++)
        {
            if (reservations[i] == &res)
            {
                return *this;
            }
        }
        // If the array needs resizing, resize it. because someone want to add the one reservation into it.
        const Reservation **newReservations = new const Reservation *[count + 1];
        // copy  existing elements to the new array
        for (size_t i = 0; i < count; i++)
        {
            newReservations[i] = reservations[i];
        }
        // add new element
        newReservations[count] = &res;

        delete[] reservations;
        reservations = newReservations;
        ++count;
        return *this;
    }

    // minus
    ConfirmationSender &ConfirmationSender::operator-=(const Reservation &res)
    { // if the address of res is not in the array, this operator does nothing
        bool found = false;
        int index = 0;
        for (size_t i = 0; i < count; i++)
        {
            if (reservations[i] == &res)
            {
                found = true;
                index = i;
                break;
            }
        }
        if (!found)
        {
            return *this;
        }
        // If found, resize the array
        const Reservation **newReservations = new const Reservation *[count - 1];
        // Copy elements except the one to be removed
        for (size_t i = 0, j = 0; i < count; ++i)
        {
            if (i != index)
            {
                newReservations[j++] = reservations[i];
            }
        }

        // Clean up old array
        delete[] reservations;

        // Update pointer and count
        reservations = newReservations;
        --count;

        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const ConfirmationSender &c)
    {
        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;
        if (c.count == 0)
        {
            os << "There are no confirmations to send!" << std::endl;
        }
        else
        {
            for (size_t i = 0; i < c.count; ++i)
            {
                os << *(c.reservations[i]); // 输出每个 Reservation 的内容
            }
        }
        os << "--------------------------" << std::endl;
        return os;
    }

}