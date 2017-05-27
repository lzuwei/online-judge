//
// Created by Li Zuwei on 10/14/16.
//
#include "../tree.h"

#ifndef EPI_10_3_H
#define EPI_10_3_H

template<typename T>
bool find_node(tree::node<T>* root, tree::node<T>* n) {
    if(root == NULL) {
        return false;
    }
    if(root == n || find_node(root->left, n) || find_node(root->right, n))
        return true;
    return false;
}

template<typename T>
tree::node<T>* find_lca_impl(tree::node<T>* root, tree::node<T>* n1, tree::node<T>* n2, bool& v1, bool& v2) {
    if(root == NULL)
        return NULL;
    if(root == n1) {
        v1 = true;
        return root;
    }
    if(root == n2) {
        v2 = true;
        return root;
    }

    tree::node<T>* left_lca = find_lca_impl(root->left, n1, n2, v1, v2);
    tree::node<T>* right_lca = find_lca_impl(root->right, n1, n2, v1, v2);

    if(left_lca && right_lca) //if n1, n2 in separate sub trees, lca is found
        return root;

    return left_lca != NULL ? left_lca : right_lca; //if n1 is not found on left, then it must be in right subtree
}

template<typename T>
tree::node<T>* find_lca(tree::node<T>* root, tree::node<T>* n1, tree::node<T>* n2) {
    bool v1 = false, v2 = false;
    tree::node<T>* lca = find_lca_impl(root, n1, n2, v1, v2);
    if((v1 && v2) || (v1 && find_node(lca, n2)) || (v2 && find_node(lca, n1)))
        return lca;
    else
        return NULL;
}
#endif //EPI_10_3_H
