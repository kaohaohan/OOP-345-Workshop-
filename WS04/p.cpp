#include <string>
#include <vector>
#include <iostream>
// trin space去頭尾的
std::string removeHeadTailSpace(const std::string &s)
{
    // 去頭尾space
    size_t start = s.find_first_not_of(' ');
    size_t last = s.find_last_not_of(' ');
    return s.substr(start, last - start + 1);
}
std::vector<std::string> handleString(const std::string &s)
{
    std::vector<std::string> data;
    std::string trimmed = removeHeadTailSpace(s);
    int index = trimmed.find(":");
    std::string numId = trimmed.substr(0, index);
    numId = removeHeadTailSpace(numId);
    data.push_back(numId);

    trimmed = trimmed.substr(index + 1);
    int nameIndex = trimmed.find(",");
    std::string name = trimmed.substr(0, nameIndex);
    name = removeHeadTailSpace(name);
    data.push_back(name);

    trimmed = trimmed.substr(nameIndex + 1);

    std::string current = "";

    for (size_t i = 0; i < trimmed.size(); i++)
    {

        char currentChar = trimmed[i];
        if (currentChar == ',')
        {
            data.push_back(current);
            current = "";
        }
        else
        {
            if (currentChar != ' ')
            {
                current += currentChar;
            }
        }
    }
    if (!current.empty())
    {
        data.push_back(current);
    }
    return data;
}

int main()
{
    std::string example = "   RES-012: Jon Snow    , john@email.com   ,2           ,   5,   16 ";

    std::vector<std::string> data = handleString(example);
    for (int i = 0; i < data.size(); i++)
        std::cout << data[i] << std::endl;

    return 1;
}
