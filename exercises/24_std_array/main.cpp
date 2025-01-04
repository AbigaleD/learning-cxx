#include "../exercise.h"
#include <array>
#include <cstring>

// READ: std::array <https://zh.cppreference.com/w/cpp/container/array>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::array<int, 5> arr{{1, 2, 3, 4, 5}};
        ASSERT(arr.size() == 5, "Fill in the correct value."); // `std::array` 的大小是模板参数指定的固定大小
        ASSERT(sizeof(arr) == 5 * sizeof(int), "Fill in the correct value."); // `sizeof(arr)` 是整个数组的大小，即每个元素大小乘以元素个数
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(arr.data(), ans, 5 * sizeof(int)) == 0, "Fill in the correct values."); // 使用 `arr.data()` 访问底层数据指针，与 `ans` 比较
    }
    {
        std::array<double, 8> arr;
        ASSERT(arr.size() == 8, "Fill in the correct value."); // `std::array` 的大小是模板参数指定的固定大小
        ASSERT(sizeof(arr) == 8 * sizeof(double), "Fill in the correct value."); // `sizeof(arr)` 是整个数组的大小，即每个元素大小乘以元素个数
    }
    {
        std::array<char, 21> arr{"Hello, InfiniTensor!"};
        ASSERT(arr.size() == 21, "Fill in the correct value."); // `std::array` 的大小是模板参数指定的固定大小
        ASSERT(sizeof(arr) == 21 * sizeof(char), "Fill in the correct value."); // 每个 `char` 1 字节，总共 21 个字符
        ASSERT(std::strcmp(arr.data(), "Hello, InfiniTensor!") == 0, "Fill in the correct value."); // 使用 `arr.data()` 作为 C 字符串指针进行比较
    }
    return 0;
}