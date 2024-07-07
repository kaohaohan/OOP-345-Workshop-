#include <iostream>
#include <iostream>
#include <vector>


int main() {
    // 创建一个整数 vector
    std::vector<int> numbers = {1, 2, 3, 4, 3, 5, 3, 6};

    // 使用迭代器遍历 vector 并删除所有值为 3 的元素
    for (auto it = numbers.begin(); it != numbers.end(); ) {
        if (*it == 3) {
            it = numbers.erase(it);  // 删除元素并更新迭代器
        } else {
            ++it;  // 仅当不删除元素时才递增迭代器
        }
    }

    // 打印修改后的 vector
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}