#include <iostream>
#include <chrono>
#include "Book.h"
#include <cstring>
#include <fstream>

using namespace std;

namespace seneca
{
    Book::Book() = default;

    Book::Book(const std::string &title, unsigned nChapters, unsigned nPages)
    {
        if (title[0] != '\0' && nChapters > 0, nPages > 0)
        {
            m_title = title;
            m_numChapters = nChapters;
            m_numPages = nPages;
        }
        {
        }
    }

    std::ostream &Book::print(std::ostream &os) const
    {
        if (!m_title.empty())
        {
            string bookInfo = m_title + "," + to_string(m_numChapters) + "," + to_string(m_numPages);
            os.width(56);
            os.setf(ios::right);
            os << bookInfo << " | ";
            os.unsetf(ios::right);

            os.setf(ios::left);
            os.width(15);
            double avgPage = static_cast<double>(m_numPages) / m_numChapters;
            string ratio = "(" + to_string(avgPage) + ")";
            os << ratio;
        }
        else
        {
            os << "| Invalid book data ";
        }
        return os;
    }

    std::ostream &operator<<(std::ostream &os, const Book &bk)
    {
        return bk.print(os);
    }
    bool Book::operator<(const Book &other) const
    {

        double ratio = static_cast<double>(m_numPages) / m_numChapters;
        double otherRatio = static_cast<double>(other.m_numPages) / other.m_numChapters;
        if (ratio < otherRatio)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Book::operator>(const Book &other) const
    {

        return !(*this < other);
    }
}