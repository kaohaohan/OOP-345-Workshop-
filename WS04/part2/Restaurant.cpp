/*
    Name: Hao Han Kao
    Seneca Email: hhao@myseneca.ca
    Seneca Student ID: 151604220
    Date: 6/9

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Restaurant.h"
#include <iostream>

namespace seneca
{
    Restaurant::Restaurant(const Reservation *reservations[], size_t cnt)
    {
        if (cnt > 0 && reservations[0] != nullptr)
        {
            this->reservations = new Reservation *[cnt];
            for (size_t i = 0; i < cnt; i++)
            {
                // new here call copy construnctor
                this->reservations[i] = new Reservation(*reservations[i]);
            }
            nums = cnt;
        }
    }
    size_t Restaurant::size() const
    {
        return nums;
    }
    Restaurant::~Restaurant()
    {
        deallocated();
    }
    void Restaurant::deallocated()
    {
        if (reservations == nullptr)
        {
            return;
        }
        else
        { // delete each dreservation pointer
            for (size_t i = 0; i < nums; i++)
            {
                delete reservations[i];
            }
        }
        delete[] reservations;
    }
    Restaurant::Restaurant(const Restaurant &other)
    {
        *this = other;
    }
    Restaurant &Restaurant::operator=(const Restaurant &other)
    {
        if (this != &other)
        {
            for (size_t i = 0; i < nums; ++i)
            {
                delete reservations[i];
            }
            delete[] reservations;

            nums = other.nums;
            reservations = new Reservation *[nums];
            for (size_t i = 0; i < nums; ++i)
            {
                reservations[i] = new Reservation(*other.reservations[i]); // deep copy
            }
        }
        return *this;
    }
    // move consturtor
    Restaurant::Restaurant(Restaurant &&other)
    {
        *this = std::move(other);
    }
    // move operator
    Restaurant &Restaurant::operator=(Restaurant &&other)
    {
        if (this != &other)
        {
            for (size_t i = 0; i < nums; ++i)
            {
                delete reservations[i];
            }
            delete[] reservations;
            nums = other.nums;
            reservations = other.reservations;
            other.reservations = nullptr;
            other.nums = 0;
        }

        return *this;
    }

    // friend
    std::ostream &operator<<(std::ostream &os, const Restaurant &r)
    {
        static int counter = 1;
        os << "--------------------------" << std::endl;
        os << "Fancy Restaurant (" << counter << ")" << std::endl;
        if (r.size() == 0)
        {
            os << "This restaurant is empty!" << std::endl;
        }
        else
        {
            for (size_t i = 0; i < r.nums; i++)
            {
                os << *r.reservations[i];
            }
        }
        os << "--------------------------" << std::endl;
        counter++;
        return os;
    }

}