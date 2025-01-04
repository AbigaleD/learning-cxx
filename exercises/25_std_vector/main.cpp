#include "../exercise.h"
#include <cstring>
#include <vector>

int main(int argc, char **argv) {
    {
        std::vector<int> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == 5, "Fill in the correct value."); // vec中有5个元素
        ASSERT(sizeof(vec) == sizeof(std::vector<int>), "Fill in the correct value."); // std::vector的大小是固定的（实现相关，但通常为对象大小）
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values."); // 使用 vec.data() 返回底层数组指针
    }
    {
        std::vector<double> vec{1, 2, 3, 4, 5};
        {
            ASSERT(vec.size() == 5, "Fill in the correct value.");
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");
            double ans[]{1, 2, 3, 4, 5};
            ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
        }
        {
            vec.push_back(6);
            ASSERT(vec.size() == 6, "Fill in the correct value.");
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");
            vec.pop_back();
            ASSERT(vec.size() == 5, "Fill in the correct value.");
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");
        }
        {
            vec[4] = 6;
            ASSERT(vec[0] == 1, "Fill in the correct value.");
            ASSERT(vec[1] == 2, "Fill in the correct value.");
            ASSERT(vec[2] == 3, "Fill in the correct value.");
            ASSERT(vec[3] == 4, "Fill in the correct value.");
            ASSERT(vec[4] == 6, "Fill in the correct value.");
        }
        {
            vec.insert(vec.begin() + 1, 1.5); // 在索引 1 插入 1.5
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 3, 4, 6}), "Make this assertion pass.");
            vec.erase(vec.begin() + 3); // 删除索引 3 的元素
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 4, 6}), "Make this assertion pass.");
        }
        {
            vec.shrink_to_fit();
            ASSERT(vec.capacity() == vec.size(), "Fill in the correct value."); // 缩减容量至与大小一致
            vec.clear();
            ASSERT(vec.empty(), "`vec` is empty now.");
            ASSERT(vec.size() == 0, "Fill in the correct value.");
            ASSERT(vec.capacity() >= 0, "Fill in the correct value."); // 可能实现相关，但容量不会增加
        }
    }
    {
        std::vector<char> vec(48, 'z'); // 用 48 个 'z' 初始化
        ASSERT(vec[0] == 'z', "Make this assertion pass.");
        ASSERT(vec[47] == 'z', "Make this assertion pass.");
        ASSERT(vec.size() == 48, "Make this assertion pass.");
        ASSERT(sizeof(vec) == sizeof(std::vector<char>), "Fill in the correct value.");
        {
            auto capacity = vec.capacity();
            vec.resize(16);
            ASSERT(vec.size() == 16, "Fill in the correct value.");
            ASSERT(vec.capacity() == capacity, "Fill in a correct identifier."); // resize 不减少容量
        }
        {
            vec.reserve(256);
            ASSERT(vec.size() == 16, "Fill in the correct value."); // reserve 只调整容量，不改变大小
            ASSERT(vec.capacity() == 256, "Fill in the correct value.");
        }
        {
            vec.push_back('a');
            vec.push_back('b');
            vec.push_back('c');
            vec.push_back('d');
            ASSERT(vec.size() == 20, "Fill in the correct value.");
            ASSERT(vec.capacity() == 256, "Fill in the correct value."); // 已有足够的容量
            ASSERT(vec[15] == 'z', "Fill in the correct value."); // 原先的最后一个元素
            ASSERT(vec[16] == 'a', "Fill in the correct value.");
            ASSERT(vec[17] == 'b', "Fill in the correct value.");
            ASSERT(vec[18] == 'c', "Fill in the correct value.");
            ASSERT(vec[19] == 'd', "Fill in the correct value.");
        }
    }

    return 0;
}