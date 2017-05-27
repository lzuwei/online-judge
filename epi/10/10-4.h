//
// Created by Li Zuwei on 10/14/16.
//
#ifndef EPI_10_4_H
#define EPI_10_4_H
#include <cmath>
#include "../tree.h"

template<typename T>
int get_depth(tree::node<T>* n) {
    int depth = 0;
    while(n->parent) {
        ++depth;
        n = n->parent;
    }
    return depth;
}

template<typename T>
tree::node<T>* find_lca_w_parent(tree::node<T>* root, tree::node<T>* n1, tree::node<T>* n2) {
    //find the depth of the nodes in n1 and n2
    int n1_depth = get_depth(n1);
    int n2_depth = get_depth(n2);

    //create 2 pointers as iterators
    tree::node<T>* n1_iter = n1;
    tree::node<T>* n2_iter = n2;

    //find the deeper node
    if(n2_depth > n1_depth)
        std::swap(n1_iter, n2_iter); //swap the deeper iterator to n1_iter

    //now move up the depth difference for the deeper node
    int depth_diff = std::abs(n1_depth - n2_depth);
    while(depth_diff--) {
        n1_iter = n1_iter->parent;
    }

    //move upwards the 2 iterators together to find common ancestor
    while(n1_iter != n2_iter) {
        n1_iter = n1_iter->parent;
        n2_iter = n2_iter->parent;
    }

    return n1_iter;
}
#endif //EPI_10_4_H
