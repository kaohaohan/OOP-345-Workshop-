#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H
#include <vector>
#include <chrono>
#include <iostream>
#include <string>

namespace seneca
{
    std::string removeHeadTailSpace(const std::string &s);
    std::vector<std::string> handleString(const std::string &s);
    class Reservation
    {
        std::string m_reservationID{};
        std::string m_name{};
        std::string m_mail{};
        int m_num_peoplel{};
        int m_day{};
        int m_time{};

    public:
        Reservation() = default;
        void update(int day, int time);
        Reservation(const std::string &res);

        // using friedn we can access private memeber variable
        friend std::ostream &operator<<(std::ostream &os, const Reservation &dt);
    };

}

#endif