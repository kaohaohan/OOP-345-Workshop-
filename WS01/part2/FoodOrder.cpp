#include <iostream>

#include "FoodOrder.h"
#include <cstring>
using namespace std;

namespace seneca{
    double g_taxrate=0.0;
    double g_dailydiscount=0.0;

   
    FoodOrder::FoodOrder()  {
       
    }
    
    // FoodOrder::FoodOrder(const char* orderDescription ){
    //     if(orderDescription!=nullptr){
    //         m_orderDescription=new char[strlen(orderDescription)+1];
    //         strcpy(m_orderDescription,orderDescription);
    //     }
    // }
    //copy construcotor
     FoodOrder::FoodOrder(const FoodOrder& other) {
        strcpy(m_custormerName, other.m_custormerName);
        m_price = other.m_price;
        m_dailySpecial = other.m_dailySpecial;
        setOrderDescription(other.m_orderDescription);
    }



    // copy operator 
    FoodOrder&  FoodOrder::operator=(const FoodOrder&FoodOrder ){
        if(this!=&FoodOrder){
           setOrderDescription(FoodOrder.m_orderDescription);
            strcpy(m_custormerName,FoodOrder.m_custormerName);
            m_price=FoodOrder.m_price;
            m_dailySpecial = FoodOrder.m_dailySpecial;     
        }
        return *this;
     }


      void FoodOrder::setOrderDescription(const char* orderDescription) {
        delete[] m_orderDescription;
        if (orderDescription) {
            m_orderDescription = new char[strlen(orderDescription) + 1];
            strcpy(m_orderDescription, orderDescription);
        } else {
            m_orderDescription = nullptr;
        }
    }

   
     FoodOrder::~FoodOrder(){
        if(m_orderDescription!=nullptr){
            delete[] m_orderDescription;
            m_orderDescription= nullptr;
        }
     }
    void FoodOrder::read(std::istream& is){
        char dailySpecial = '\0';
        char tempDescription[256]={0};
        char tempName[10]={0};
        m_custormerName[0]='\0';
        if(!is){ 
            return;
        }else{
            if(!is.getline(tempName, 10, ',')){
                return;
            }
            strncpy(m_custormerName,tempName,9);
           is.getline(tempDescription, 256, ',');
           if (strlen(tempDescription)>0){
                setOrderDescription(tempDescription);
           }
   
           is >> m_price;
           is.ignore(); // deal with ,
           is >> dailySpecial;
           is.ignore(1000,'\n');
      
           if(dailySpecial=='Y'){
            m_dailySpecial=true;
           }else if (dailySpecial=='N'){
            m_dailySpecial=false;
           }else{
             is.ignore(1000, '\n');
             return;
           }
            
        }
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