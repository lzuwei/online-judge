//
// Created by Li Zuwei on 10/9/16.
//
#ifndef EPI_TREE_H
#define EPI_TREE_H
#include <list>
#include <algorithm>
#include <cmath>

namespace tree {
template<typename T>
struct node {
    T data;
    node* left;
    node* right;
    node* parent;
    node(T data): data(data), left(NULL), right(NULL), parent(NULL) {}
};
}

template<typename T>
void pre_order(tree::node<T>* node) {
    if(node == NULL)
        return;
    std::cout << node->data << " ";
    pre_order(node->left);
    pre_order(node->right);
}

template<typename T>
void in_order(tree::node<T>* node) {
    if(node == NULL)
        return;
    in_order(node->left);
    std::cout << node->data << " ";
    in_order(node->right);
}

template<typename T>
void post_order(tree::node<T>* node) {
    if(node == NULL)
        return;
    post_order(node->left);
    post_order(node->right);
    std::cout << node->data << " ";
}

template<typename T>
void level_order(tree::node<T>* node) {
    std::list<tree::node<T>*> queue;
    tree::node<T>* temp = node;
    while(temp) {
        std::cout << temp->data << " ";
        if(temp->left)
            queue.push_back(temp->left);
        if(temp->right)
            queue.push_back(temp->right);
        if(!queue.empty()) {
            temp = queue.front();
            queue.pop_front();
        }
        else {
            temp = NULL;
        }
    }
}

template<typename T>
int height(tree::node<T>* node) {
    if(node == NULL)
        return 0;
    else
        return 1 + std::max(height(node->left), height(node->right));
}


#endif //EPI_TREE_H
