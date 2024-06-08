#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <chrono>
#include <iostream>
#include <string>

namespace seneca
{
    class Book
    {
        std::string m_title{};
        unsigned m_numChapters{};
        unsigned m_numPages{};

    public:
        Book();
        // 初始化這段
        Book(const std::string &title, unsigned nChapters, unsigned nPages);

        bool operator<(const Book &other) const;
        bool operator>(const Book &other) const;
        std::ostream &print(std::ostream &os) const;
    };
    std::ostream &operator<<(std::ostream &os, const Book &bk);
}

#endif