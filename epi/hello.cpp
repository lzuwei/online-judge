//
// Created by Li Zuwei on 10/9/16.
//
#include <iostream>
#include <random>
#include "tree.h"
#include "utils/bits.h"
#include "7/7-1.h"
#include "7/7-5.h"
#include "7/7-6.h"
#include "10/10-1.h"
#include "11/11-6.h"
using namespace tree;
#include <random>
#include <vector>
#include <functional>
#include <iostream>
#include "12/12-8.h"

int generate_random_int(int start, int end) {
    std::default_random_engine gen((std::random_device())());
    std::uniform_int_distribution<int> dis(start, end);
    return dis(gen);
}

void test_quicksort() {
    std::vector<int> A = {12,3,56,8,23,1,0};
    A = quicksort(0, A.size()-1, std::less_equal<int>(), A);
    for (int i : A) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    test_quicksort();
    /*
    std::cout << count_bits(7) << std::endl;
    std::cout << "int to string: " << int_to_string(12345) << std::endl;
    std::cout << "string to int: " << string_to_int("12345") << std::endl;
    std::cout << "is palindrome: " << is_palindromic_sentence("Able was I, ere I saw Elba!") << std::endl;
    std::cout << "reverse sentence: " << reverse_words("Hello hello There") << std::endl;
    std::string s("hello world");

    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr)/sizeof(arr[0]), k = 2;
    std::cout << "K'th smallest element is " << kthSmallest(arr, n, k) << std::endl;
    std::cout << "random number btw 1 to 6: " << generate_random_int(1, 6) << std::endl;
     */
}

