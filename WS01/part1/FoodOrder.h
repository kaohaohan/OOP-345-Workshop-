#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#include <iostream>
namespace seneca{
    extern double g_taxrate;
    extern double g_dailydiscount;
    
    class FoodOrder{
        private:
        char m_custormerName[11];
        char m_orderDescription[26];
        double m_price;
        bool m_dailySpecial;
        public:
        FoodOrder();
        void read(std::istream& );
        void display() const;
    };
}

#endif