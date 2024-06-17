#include "SpellChecker.h"
#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

namespace seneca{
    //初始化
   size_t SpellChecker::m_count[6]={0};

   SpellChecker::SpellChecker(const char* filename){
     std::ifstream inputFile(filename);
        if(!inputFile){
            throw "Bad file name!";
        }else{
            std::string line;
            int i=0;
            while (std::getline(inputFile, line)) {
                std::vector<std::string> words;
                std::regex ws_re("\\s+"); // 正则表达式匹配一个或多个空白字符
                std::sregex_token_iterator it(line.begin(), line.end(), ws_re, -1);
                std::sregex_token_iterator end;
                for (; it != end; ++it) {
                    if (!it->str().empty()) {
                        words.push_back(it->str());
                    }
                }
                if (words.size() == 2) {
                    m_badWords[i] = words[0];
                    m_goodWords[i] = words[1];
                    i++;
                }
            }
        }
  };
  void SpellChecker::operator()(std::string& text){
        for (int i=0;i<6;i++){
            std::string badWord = m_badWords[i];
            std::string goodWord = m_goodWords[i];
            size_t index = text.find(badWord);
            while (index != std::string::npos) {
                text.replace(index, badWord.length(), goodWord);
                // 更新索引位置，从当前替换的位置之后继续查找
                m_count[i] ++;
                index = text.find(badWord, index + goodWord.length());
            }
        }  
  }
  void SpellChecker::showStatistics(std::ostream& os) const{
        os << "Spellchecker Statistics" << std::endl;
    for (size_t i = 0; i < 6; i++) {
        os.width(15);
        os.setf(std::ios::right);
        os << m_badWords[i];
        os << ": ";
        os.unsetf(std::ios::right);
        os << m_count[i] << " replacements" << std::endl;
    }
  }

}