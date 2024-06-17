#include "Movie.h"
#include <vector>
#include <cstring>
#include <iostream>

namespace seneca{
    const std::string&Movie::title() const{
        return m_title;
    }

     // trin space去頭尾的
    std::string removeHeadTailSpace2(const std::string &s)
    {
        // 去頭尾space
        size_t start = s.find_first_not_of(' ');
        size_t last = s.find_last_not_of(' ');
        return s.substr(start, last - start + 1);
    }
    Movie::Movie(const std::string& strMovie){
        std::vector<std::string> data;
        std::string word;

        int count =0;
        for(size_t i=0;i<strMovie.size();i++){
            char c=strMovie[i];
            if(c!=','&& count<2){
                word+=c;
            }else{
                if (count<2) {
                    word= removeHeadTailSpace2(word);
                    data.push_back(word);
                    count++;
                    word.clear();
                } else {
                     word+=c;
                }

            }
        }
        word= removeHeadTailSpace2(word);
        data.push_back(word);

        // updated data 
        m_title= data[0];
        m_year =std::stoi(data[1]);
        m_description = data[2];

    }

   std::ostream &operator<<(std::ostream &os, const Movie &m) {
    os.width(40);
    os << m.m_title << " | ";
    os.width(4);
    os << m.m_year << " | ";
    os << m.m_description << std::endl;
    return os;
}
}
