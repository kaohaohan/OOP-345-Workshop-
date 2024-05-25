#include <iostream>

#include "FoodOrder.h"
#include <cstring>
using namespace std;

namespace seneca{
    double g_taxrate=0.0;
    double g_dailydiscount=0.0;

    FoodOrder::FoodOrder(): m_price(0.0), m_dailySpecial(false) {
        m_custormerName[0]='\0';
        m_orderDescription[0]='\0';
    }

    

    void FoodOrder::read(std::istream& is){
        char dailySpecial = '\0';
        if(!is){
            return;
        }else{
           is.getline(m_custormerName, 11, ',');
           is.getline(m_orderDescription, 26, ',');
           is >> m_price;
           is.ignore(); // deal with ,
           is >> dailySpecial;

           if(dailySpecial=='Y'){
            m_dailySpecial=true;
           }else if (dailySpecial=='N'){
            m_dailySpecial=false;
           }else{
             is.ignore(1000, '\n');
             return;
           }
            
        }
        is.ignore(1000, '\n');
    }
    void FoodOrder::display() const{
        static int counter=0;
        ++counter;
        cout.width(2);
        cout.setf( ios::left ); 
        cout << counter <<". ";
        if(m_custormerName[0]!='\0'){
            cout.width(10);
            cout << m_custormerName<< "|";
            cout.width(25);
            cout <<m_orderDescription<<"|";
            cout.width(12);
            cout.setf( ios::fixed );
            cout.precision( 2 );
            cout << m_price* (1+g_taxrate) << "|";
            
            if(m_dailySpecial){
                cout.unsetf( ios::left );
                cout.setf(ios::right);
                cout.width(13);
               
                cout <<  (m_price * (1 + g_taxrate) - g_dailydiscount);
                cout.unsetf( ios::fixed );
                cout.unsetf(ios::right);
            }
            cout << endl;
            
        }else{
            cout  << "No Order"<< endl;
        }
    }
}   