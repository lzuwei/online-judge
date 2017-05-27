//
// Created by Li Zuwei on 10/12/16.
//

#ifndef EPI_10_1_H
#define EPI_10_1_H
#include <cmath>
#include "../tree.h"

template<typename T>
bool is_balanced(tree::node<T>* node, int* height) {
    if(node == NULL) {
        *height = 0;
        return true;
    }
    int lh = 0, rh = 0;
    bool l_bal = is_balanced(node->left, &lh);
    bool r_bal = is_balanced(node->right, &rh);

    *height = std::max(lh, rh) + 1;
    if(std::abs(lh - rh) > 1) {
        return false;
    }
    return l_bal && r_bal;
}

template<typename T>
int find_largest_complete_subtree(tree::node<T>* root) {
    if(root == NULL) {
        return 0;
    }

}
#endif //EPI_10_1_H
