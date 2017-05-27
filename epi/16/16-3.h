//
// Created by Li Zuwei on 10/16/16.
//

#ifndef EPI_16_3_H
#define EPI_16_3_H
#include <vector>
#include <utility>
using namespace std;

void permutate(int i, std::vector<int>& A, std::vector<std::vector<int> >& results) {
    if(i == A.size() - 1) { //reached the end store results
        results.emplace_back(A);
        return;
    }
    for(int j = i; j < A.size(); ++j) {
        std::swap(A[i], A[j]); //swap permutations
        permutate(i + 1, A, results); //permutate i + 1
        std::swap(A[i], A[j]);
    }
}

void permutate_with_dup(int i, std::vector<int>& A, std::vector<std::vector<int> >& results) {
    static int lastChar = 0;
    if( i == A.size() - 1 )
    { // We have a permutation so print it
        results.emplace_back(A);
        return;
    }
    // Permutate once without any swaps.
    permutate( i + 1, A, results);
    lastChar = A[i];
    for( int j = i + 1; j < A.size(); ++j)
    {
        if( lastChar == A[j] ) {
            continue;
        } else {
            lastChar = A[j];
        }
        std::swap( A[i], A[j] ); // It doesn't matter how you swap.
        permutate_with_dup( i + 1, A, results );
        std::swap( A[i], A[j] );
    }

}

std::vector<std::vector<int>> generate_permutations(std::vector<int> A, bool with_dup=false) {
    std::vector<std::vector<int> > results;
    if(with_dup)
        permutate_with_dup(0, A, results);
    else
        permutate(0, A, results);
    return results;
}
#endif //EPI_16_3_H
