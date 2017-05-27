//
// Created by Li Zuwei on 10/15/16.
//
#include <vector>
#include <iostream>
#include "11/11-1.h"

void q11_1() {
    std::vector<std::vector<int> > arrays = {{0,2,3,5,7},
                                             {0,1},
                                             {6,8,10,11,12}};
    std::vector<int> results = merge_sorted_arrays(arrays);
    for(int i : results)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    q11_1();
}