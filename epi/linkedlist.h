//
// Created by Li Zuwei on 10/10/16.
//

#ifndef EPI_LINKEDLIST_H
#define EPI_LINKEDLIST_H
#include <cstddef>
#include <memory>
namespace linkedlist {
template<typename T>
struct node {
    T data;
    node<T>* next;
    node(T item) : data(item), next(NULL) {}
};
}

template<typename T>
struct list_node {
    T data;
    std::shared_ptr<list_node<T>> next;
};

#endif //EPI_LINKEDLIST_H
