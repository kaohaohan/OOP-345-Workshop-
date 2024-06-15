#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <chrono>
#include <iostream>
#include <string>

namespace seneca{
class Book{
    std::string m_title{}; //如果要用 char 是char* 
    std::string m_author{};
    std::string m_countryPublication{};
    size_t m_year{};
    double m_price{}; 
    std::string m_description{};
    public:
    Book()=default;

    // a query that returns the title of the book
    const std::string& title() const;
    //: a query that returns the publication country
    const std::string& country() const;

    // a query that returns the publication year
    const size_t& year() const;

    //a function that returns the price by reference, allowing the client code to update the price
    double& price();

    //
    Book(const std::string& strBook);
    friend std::ostream &operator<<(std::ostream &os, const Book &b);

} ;
}
#endif