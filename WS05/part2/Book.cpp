#include "Book.h"
#include <vector>
#include <cstring>
#include <iostream>
namespace seneca{

    const std::string& Book::title() const{
        return m_title;
    }


    const std::string& Book::country() const{
        return m_countryPublication;
    }

    const size_t& Book::year() const{
        return m_year;
    }


      double& Book::price(){
        return m_price;
      }

//Miguel de Cervantes,     Don Quixote,     Spain,    9.99,    1612,   The story follows a Hidalgo, Alonso Quixano, who proves that chivalry will in fact never die.


     // trin space去頭尾的
    std::string removeHeadTailSpace(const std::string &s)
    {
        // 去頭尾space
        size_t start = s.find_first_not_of(' ');
        size_t last = s.find_last_not_of(' ');
        return s.substr(start, last - start + 1);
    }
        
    
    Book::Book(const std::string& strBook){
        std::vector<std::string> data;
        std::string word;
        //size()會return size_t
        int count =0;
        for (size_t i=0;i<strBook.size();i++){
            char c =strBook[i]; 
            if(c!=','&& count<5){
                word+=c;
            }else{
                if (count<5) {
                    word= removeHeadTailSpace(word);
                    data.push_back(word);
                    count++;
                    word.clear();
                } else {
                     word+=c;
                }

            }
        } 
        word= removeHeadTailSpace(word);
        data.push_back(word);

        //put data into Book variables 
        m_author= data[0];
        m_title =data[1];
        m_countryPublication =data[2];
        m_price =std::stod(data[3]);
        m_year =std::stoi(data[4]);
        m_description = data[5];
        
    }

    std::ostream &operator<<(std::ostream &os, const Book &b){
        os.width(20);
        os << b.m_author << " | ";
        os.width(22);
        os << b.m_title << " | ";
        os.width(5);
        os <<b.m_countryPublication << " | ";
        os.width(4);
        os << b.m_year << " | ";
        os.width(6);
        os.setf(std::ios::fixed);
        os.precision(2);
        os << b.m_price << " | ";
        os << b.m_description << std::endl;
        return os;
    }
}