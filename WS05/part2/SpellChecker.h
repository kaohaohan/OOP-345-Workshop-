#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <chrono>
#include <iostream>
#include <string>

namespace seneca{
    class SpellChecker{
        std::string m_badWords[6]{};
        std::string  m_goodWords[6]{};
        static size_t m_count[6];
        public:
        SpellChecker()=default;
        SpellChecker(const char* filename);
        //functor
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}


#endif