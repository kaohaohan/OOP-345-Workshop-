#include <iostream>
#include <string>
#include <array>

class SpellChecker {
    std::array<std::string, 6> m_badWords;
    std::array<std::string, 6> m_goodWords;
    std::array<int, 6> m_count;

public:
    SpellChecker() {
        // 初始化 badWords 和 goodWords
        m_badWords = {"teh", "modiffied", "begim", "famillies", "Dork", "hibrid"};
        m_goodWords = {"the", "modified", "begin", "families", "Dark", "hybrid"};
        m_count.fill(0);
    }

    void operator()(std::string& text) {
        if (!m_badWords[0].empty() && !m_goodWords[0].empty()) {
            for (int i = 0; i < 6; i++) {
                std::string badWord = m_badWords[i];
                std::string goodWord = m_goodWords[i];
                size_t index = text.find(badWord);
                while (index != std::string::npos) {
                    m_count[i] += 1;
                    text.replace(index, badWord.length(), goodWord);
                    // 更新索引位置，从当前替换的位置之后继续查找
                    index = text.find(badWord, index + goodWord.length());
                }
            }
        }
    }

    void printCounts() const {
        for (int i = 0; i < 6; ++i) {
            std::cout << "Replacement count for '" << m_badWords[i] << "': " << m_count[i] << std::endl;
        }
    }
};

int main() {
    SpellChecker checker;
    std::string text = "This is teh modiffied begim of famillies. Dork is not a hibrid.";

    std::cout << "Original text: " << text << std::endl;
    
    checker(text);

    std::cout << "Processed text: " << text << std::endl;
    checker.printCounts();

    return 0;
}
