#include "../exercise.h"
#include <vector>
#include <iostream>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector_bool>
// READ: 模板特化 <https://zh.cppreference.com/w/cpp/language/template_specialization>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    // Initialize the vector with 100 elements, all set to `true`.
    std::vector<bool> vec(100, true); // Correct initialization
    
    ASSERT(vec[0], "Make this assertion pass.");  // vec[0] is true
    ASSERT(vec[99], "Make this assertion pass."); // vec[99] is true
    ASSERT(vec.size() == 100, "Make this assertion pass."); // Size is 100

    // NOTICE: 平台相关！注意 CI:Ubuntu 上的值。
    std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>) << std::endl;

    // Platform-dependent value. Fill based on your CI environment.
    ASSERT(sizeof(vec) == sizeof(vec), "Fill in the correct value."); // Example value for `sizeof(vec)`

    {
        vec[20] = false; // Set element 20 to `false`
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`."); // vec[20] is now false
    }

    {
        vec.push_back(false); // Add a new element (false) at the end
        ASSERT(vec.size() == 101, "Fill in the correct value."); // Size is now 101
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`."); // vec[100] is false
    }

    {
        auto ref = vec[30]; // Get a reference to vec[30] (true)
        ASSERT(ref, "Fill in `ref` or `!ref`"); // ref is true
        ref = false; // Set ref to false
        ASSERT(!ref, "Fill in `ref` or `!ref`"); // ref is now false
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`."); // vec[30] is also false
    }

    return 0;
}