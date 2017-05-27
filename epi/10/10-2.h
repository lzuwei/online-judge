//
// Created by Li Zuwei on 10/14/16.
//

#ifndef EPI_10_2_H
#define EPI_10_2_H
#include "../tree.h"

template<typename T>
bool check_symmetry(const tree::node<T>* left, const tree::node<T>* right) {
    if(left == NULL && right == NULL)
        return true;
    else if(left != NULL && right != NULL) {
        return left->data == right->data &&
                check_symmetry(left->left, right->right) &&
                check_symmetry(left->right, right->left);
    }
    return false;
}

template<typename T>
bool is_symmetric(tree::node<T>* tree) {
    return tree == NULL || check_symmetry(tree->left, tree->right);
}
#endif //EPI_10_2_H
