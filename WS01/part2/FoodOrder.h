#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#include <iostream>
namespace seneca{
    extern double g_taxrate;
    extern double g_dailydiscount;
    
    class FoodOrder{
        private:
        char m_custormerName[11]{}; // default-initialized to '\0'
        char* m_orderDescription{nullptr};
        double m_price{0.0};
        bool m_dailySpecial{false};
        void setOrderDescription(const char* m_orderDescription);
        public:
        FoodOrder();
        // FoodOrder(const char* orderDescription );
         FoodOrder(const FoodOrder& other);
        FoodOrder& operator=(const FoodOrder&FoodOrder );
        void read(std::istream& is);
        void display() const;
        ~FoodOrder();
    };
}

#endif