//
// Created by Li Zuwei on 10/15/16.
//

#ifndef EPI_11_1_H
#define EPI_11_1_H
#include <queue>
#include <vector>

template<typename T>
struct iterator_curr_end {
    bool operator> (const iterator_curr_end<T>& that) const { //implement min heap using greater than operation
        return *current > *that.current;
    }
    typename std::vector<T>::const_iterator current;
    typename std::vector<T>::const_iterator end;
};

template<typename T>
std::vector<T> merge_sorted_arrays(const std::vector<std::vector<T> >& sorted_arrays) {
    std::priority_queue<iterator_curr_end<T>, std::vector<iterator_curr_end<T> >, std::greater<iterator_curr_end<T> > > min_heap;

    //populate the min heap with the smallest elements of each array (iterator)
    for(const std::vector<T>& sorted_array : sorted_arrays) {
        if(!sorted_array.empty()) {
            min_heap.emplace(iterator_curr_end<T>{sorted_array.cbegin(), sorted_array.cend()});
        }
    }

    std::vector<T> results;
    while(!min_heap.empty()) {
        iterator_curr_end<T> smallest_array = min_heap.top();
        min_heap.pop();
        if(smallest_array.current != smallest_array.end) {
            results.emplace_back(*smallest_array.current);
            min_heap.emplace(iterator_curr_end<T>{std::next(smallest_array.current), smallest_array.end});
        }
    }
    return results;
}
#endif //EPI_11_1_H
