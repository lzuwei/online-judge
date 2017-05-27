//
// Created by Li Zuwei on 10/16/16.
//
#include "16/16-3.h"
#include <vector>
#include <iostream>
int main() {
    //std::vector<int> A = {2,2,3,0};
    std::vector<int> A = {5,7,3};
    std::vector<std::vector<int>> res = generate_permutations(A, false);
    for(std::vector<int> p : res) {
        for(int i : p)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}

