﻿#include "../exercise.h"
#include <cmath>

enum class DataType {
    Float,
    Double,
};

/// @brief Tagged union 即标签化联合体，是联合体的一种常见应用。
///        Rust enum 在实现上就是标签化联合体。
struct TaggedUnion {
    DataType type;
    union {
        float f;
        double d;
    };
};

// 模板化的 sigmoid 函数
template <typename T>
T sigmoid(T x) {
    return 1 / (1 + std::exp(-x));
}

// 处理 TaggedUnion 的 sigmoid_dyn 函数
TaggedUnion sigmoid_dyn(TaggedUnion x) {
    TaggedUnion ans{x.type};
    if (x.type == DataType::Float) {
        ans.f = sigmoid(x.f); // 调用模板实例化的 sigmoid<float>
    } else if (x.type == DataType::Double) {
        ans.d = sigmoid(x.d); // 调用模板实例化的 sigmoid<double>
    }
    return ans;
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    TaggedUnion xf{DataType::Float};
    xf.f = 5.f;
    auto yf = sigmoid_dyn(xf);
    ASSERT(yf.type == DataType::Float, "type mismatch");
    ASSERT(yf.f == 1 / (1 + std::exp(-5.f)), "sigmoid float");

    TaggedUnion xd{DataType::Double};
    xd.d = 5.0;
    auto yd = sigmoid_dyn(xd);
    ASSERT(yd.type == DataType::Double, "type mismatch");
    ASSERT(yd.d == 1 / (1 + std::exp(-5.0)), "sigmoid double");
    return 0;
}