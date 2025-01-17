﻿#include "../exercise.h"
#include <numeric>
#include <iostream>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    
    // Calculate the total number of elements in the tensor
    int total_elements = std::accumulate(std::begin(shape), std::end(shape), 1, std::multiplies<int>());
    
    // Calculate the total size in bytes
    int size = total_elements * sizeof(DataType);
    
    // Verify the result
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    
    return 0;
}