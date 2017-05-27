//
// Created by Li Zuwei on 10/24/16.
//

#ifndef EPI_10_12_H
#define EPI_10_12_H
struct node {
    char data;
    struct node* left;
    struct node* right;

    node(char data) {
        this.data = data;
        left = NULL;
        right = NULL;
    }
};

int search(char arr[], int start, int end, char value) {
    for(int i = start; i <= end; ++i) {
        if(arr[i] == value)
            return i;
    }
}

struct node* build_tree(char in[], char pre[], int in_start, int in_end) {
    static int pre_index = 0;
    if(in_start > in_end) //no more children
        return NULL;

    struct node* new_node = new node(pre[pre_index++]);
    if(in_start == in_end) // single node tree, we are done
        return new_node;

    // if not find the node in the in order list to split the left and right subtree
    int in_idx = search(in, in_start, in_end, new_node->data);
    new_node->left = build_tree(in, pre, in_start, in_idx - 1);
    new_node->right = build_tree(in, pre, in_idx + 1, in_end);

    return new_node;
}
#endif //EPI_10_12_H
