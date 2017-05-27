//
// Created by Li Zuwei on 10/16/16.
//

#ifndef EPI_12_8_H
#define EPI_12_8_H
#include <vector>
#include <random>
using namespace std;

template<typename T, typename Compare>
int partition(int left, int right, Compare comp, std::vector<T>& A) {
    int i = left, j = right;
    int pivot_idx = (left + right) / 2;
    int tmp;
    while(i <= j) {
        while(comp(A[i], A[pivot_idx]) && i <= right)
            i++;
        while(!comp(A[j], A[pivot_idx]) && j >= left)
            j--;
        if(i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    return i;
};

template<typename T, typename Compare>
vector<T>& quicksort(int left, int right, Compare comp, vector<T>& A) {
    int index = partition(left, right, comp, A);
    if(left < index - 1)
        quicksort(left, index - 1, comp, A);
    if(index < right)
        quicksort(index, right, comp , A);
    return A;
};

template<typename Compare>
int partition_around_pivot(int left, int right, int pivot_idx, Compare comp, std::vector<int>* A_ptr) {
    vector<int>& A = *A_ptr;
    int pivot_value = A[pivot_idx];
    int new_pivot_idx = left;
    swap(A[pivot_idx], A[right]);
    for(int i = left; i < right; ++i) {
        if(comp(A[i], pivot_value)) {
            swap(A[i], A[new_pivot_idx++]);
        }
    }
    swap(A[right], A[new_pivot_idx]);
    return new_pivot_idx;
}

template <typename Compare>
int find_kth(int k, Compare comp, vector<int>* A_ptr) {
    vector<int>& A = *A_ptr;
    int left = 0, right = A.size()-1; //initialize the indexes
    default_random_engine gen;
    while(left <= right) {
        uniform_int_distribution<int> distribution(left, right);
        int pivot_idx = distribution(gen);
        int new_pivot_idx = partition_around_pivot(left, right, pivot_idx, comp, &A);
        if (new_pivot_idx == k - 1) { //at correct idx
            return new_pivot_idx;
        } else if (new_pivot_idx > k - 1) { //at larger than kth idx, shift pivot leftwards
            right = new_pivot_idx - 1;
        } else {
            left = new_pivot_idx + 1; // partition from pivot idx to right to shift pivot rightwards
        }
    }
}
#endif //EPI_12_8_H
