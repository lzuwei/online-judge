//
// Created by Li Zuwei on 10/14/16.
//

#ifndef EPI_10_7_H
#define EPI_10_7_H
#include "../tree.h"
#include <vector>
#include <stack>
template<typename T>
std::vector<T> non_recursive_inorder(tree::node<T>* root) {
    std::stack<tree::node<T>*> s;
    std::vector<T> result;
    tree::node<T>* curr = root;
    while(!s.empty() || curr) {
        if(curr) {
            s.push(curr);
            //go left
            curr = curr->left;
        }
        else {
            curr = s.top();
            result.push_back(curr->data);
            s.pop();
            //go right
            curr = curr->right;
        }
    }
    return result;
}
#endif //EPI_10_7_H
