﻿#include "../exercise.h"
#include <algorithm>
#include <string>
#include <vector>
#include <cassert> // 确保包含断言库

int main(int argc, char **argv) {
    std::vector<int> val{8, 13, 21, 34, 55};
    std::vector<std::string> ans(val.size());

    // 使用 std::transform 将每个元素乘以 2 并转换为字符串
    std::transform(val.begin(), val.end(), ans.begin(),
                   [](int x) { return std::to_string(x * 2); });

    // 检查 ans 的结果是否符合预期
    ASSERT(ans.size() == val.size(), "ans size should be equal to val size");
    ASSERT(ans[0] == "16", "ans[0] should be 16");
    ASSERT(ans[1] == "26", "ans[1] should be 26");
    ASSERT(ans[2] == "42", "ans[2] should be 42");
    ASSERT(ans[3] == "68", "ans[3] should be 68");
    ASSERT(ans[4] == "110", "ans[4] should be 110");

    return 0;
}