//
// Created by Li Zuwei on 10/14/16.
//
#include <iostream>
#include <vector>
#include "tree.h"
#include "10/10-1.h"
#include "10/10-2.h"
#include "10/10-3.h"
#include "10/10-4.h"
#include "10/10-7.h"

void q10_1() {
    tree::node<int> n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.data = 1;
    n2.data = 2;
    n3.data = 3;
    n4.data = 4;
    n2.left = &n1;
    n2.right = &n3;
    n3.right = &n4;
    int ht = 0;
    in_order(&n2);
    std::cout << std::endl;
    pre_order(&n2);
    std::cout << std::endl;
    post_order(&n2);
    std::cout << std::endl;
    level_order(&n2);
    std::cout << std::endl;
    std::cout << "is balanced: " << is_balanced(&n2, &ht) << std::endl;
}

void q10_2() {
    tree::node<int> a(314);
    tree::node<int> b(6);
    tree::node<int> c(2);
    tree::node<int> d(3);
    tree::node<int> e(6);
    tree::node<int> f(2);
    tree::node<int> g(3);
    a.left = &b;
    b.right = &c;
    c.right = &d;
    a.right = &e;
    e.left = &f;
    f.left = &g;
    std::cout << "is symmetric: " << is_symmetric(&a) << std::endl;
}

void q10_3() {
    tree::node<int> a(314);
    tree::node<int> b(12);
    tree::node<int> c(6);
    tree::node<int> d(7);
    tree::node<int> e(4);
    tree::node<int> f(9);
    tree::node<int> g(8);
    a.left = &b;
    b.left = &d;
    d.left = &f;
    d.right = &g;
    b.right = &e;
    a.right = &c;
    std::cout << "lca: " << find_lca(&a, &f, &e)->data << std::endl;
}

void q10_4() {
    tree::node<int> a(314);
    tree::node<int> b(12);
    tree::node<int> c(6);
    tree::node<int> d(7);
    tree::node<int> e(4);
    tree::node<int> f(9);
    tree::node<int> g(8);
    a.left = &b;
    b.left = &d;
    d.left = &f;
    d.right = &g;
    b.right = &e;
    a.right = &c;
    d.parent = &b;
    b.parent = &a;
    f.parent = &d;
    g.parent = &d;
    e.parent = &b;
    c.parent = &a;
    std::cout << "lca using parent pointer: " << find_lca_w_parent(&a, &f, &e)->data << std::endl;
}

void q10_7() {
    tree::node<int> a(314);
    tree::node<int> b(12);
    tree::node<int> c(6);
    tree::node<int> d(7);
    tree::node<int> e(4);
    tree::node<int> f(9);
    tree::node<int> g(8);
    a.left = &b;
    b.left = &d;
    d.left = &f;
    d.right = &g;
    b.right = &e;
    a.right = &c;
    std::vector<int> v = non_recursive_inorder(&a);
    for (int i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    q10_7();
}