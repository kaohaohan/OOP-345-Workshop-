/*
    Name: Hao Han Kao
    Seneca Email: hhao@myseneca.ca
    Seneca Student ID: 151604220
    Date: 6/9

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Reservation.h"
#include <iostream>
#include <chrono>
#include <cstring>
#include <vector>
#include <iomanip>
namespace seneca
{
    // trin space去頭尾的
    std::string removeHeadTailSpace(const std::string &s)
    {
        // 去頭尾space
        size_t start = s.find_first_not_of(' ');
        size_t last = s.find_last_not_of(' ');
        return s.substr(start, last - start + 1);
    }
    std::vector<std::string> handleString(const std::string &s)
    {
        std::vector<std::string> data;
        std::string trimmed = removeHeadTailSpace(s);
        int index = trimmed.find(":");
        std::string numId = trimmed.substr(0, index);
        numId = removeHeadTailSpace(numId);
        data.push_back(numId);

        trimmed = trimmed.substr(index + 1);
        int nameIndex = trimmed.find(",");
        std::string name = trimmed.substr(0, nameIndex);
        name = removeHeadTailSpace(name);
        data.push_back(name);

        trimmed = trimmed.substr(nameIndex + 1);

        std::string current = "";

        for (size_t i = 0; i < trimmed.size(); i++)
        {

            char currentChar = trimmed[i];
            if (currentChar == ',')
            {
                data.push_back(current);
                current = "";
            }
            else
            {
                if (currentChar != ' ')
                {
                    current += currentChar;
                }
            }
        }
        if (!current.empty())
        {
            data.push_back(current);
        }
        return data;
    }

    void Reservation::update(int day, int time)
    {
        m_day = day;
        m_time = time;
    }
    Reservation::Reservation(const std::string &res)
    {
        std::vector<std::string> data = handleString(res);
        // Assuming the input string is always correctly formatted
        m_reservationID = data[0];
        m_name = data[1];
        m_mail = data[2];
        m_num_peoplel = std::stoi(data[3]);
        m_day = std::stoi(data[4]);
        m_time = std::stoi(data[5]);
    }

    std::ostream &operator<<(std::ostream &os, const Reservation &r)
    {
        // handle different time zone and named the meal name
        std::string meal;
        if (r.m_time >= 6 && r.m_time <= 9)
        {
            meal = "Breakfast";
        }
        else if (r.m_time >= 11 && r.m_time <= 15)
        {
            meal = "Lunch";
        }
        else if (r.m_time >= 17 && r.m_time <= 21)
        {
            meal = "Dinner";
        }
        else
        {
            meal = "Drinks";
        }

        // handling how many people
        std::string people = r.m_num_peoplel == 1 ? "person" : "people";
        // Reservation    RES-020:                Donna  <donna@email.com>       Drinks on day 4 @ 24:00 for 3 people.
        // Reservation ID: NAME  <email>    Breakfast on day DAY @ HOUR:00 for #PARTY_SIZE people.
        os << "Reservation " << std::setw(10) << std::right << r.m_reservationID << ": "
           << std::setw(20) << std::right << r.m_name << "  "
           << std::setw(20) << std::left << "<" + r.m_mail + ">" << "    "
           << meal << " on day " << r.m_day << " @ " << r.m_time << ":00 for "
           << r.m_num_peoplel << " " << people << "." << std::endl;

        return os;
    }

}