#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include <chrono>
#include <iostream>
#include <string>

namespace seneca{
    class Movie
    {
        std::string m_title{};
        size_t m_year{};
        std::string m_description{};
    public:
        template <typename T>
        void fixSpelling(T& spellChecker){
             spellChecker(m_title);
            spellChecker(m_description);
        };

        Movie()=default;
        const std::string& title() const;
        Movie(const std::string& strMovie);

        friend std::ostream &operator<<(std::ostream &os, const Movie &m);
    };
    
}
#endif



