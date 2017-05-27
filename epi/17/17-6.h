//
// Created by Li Zuwei on 10/23/16.
//

#ifndef EPI_17_6_H
#define EPI_17_6_H
#include <vector>

using namespace std;

struct item {
    int weight;
    int value;
};

/**
 * v[i][w] = max(v[i-1][w], v[i-1][w-wi] + vi), if wi < w; or v[i-1][w] otherwise
 * @param items
 * @param k
 * @param capacity_left
 * @param v
 * @return
 */
int compute_optimum_knapsack(const vector<item>& items, int k, int capacity_left, vector<vector<int>>& v) {
    if(k < 0)
        return 0;

    if(v[k][capacity_left] == -1) {
        //unfilled compute the optimum knapsack for this capacity
        int without_curr_item = compute_optimum_knapsack(items, k-1, capacity_left, v);
        int with_curr_item = capacity_left < items[k].weight ?
                             0 : items[k].value + compute_optimum_knapsack(items, k-1, capacity_left - items[k].weight, v);
        v[k][capacity_left] = max(without_curr_item, with_curr_item);
    }
    return v[k][capacity_left];
}

int find_optimum_knapsack(const vector<item>& items, int capacity) {
    //V[i][j] holds the optimum value when we chose from items[0:i]
    //and have the capacity of j
    //add +1 to hold a record for the base case where the weight/capacity is 0.
    vector<vector<int>> v(items.size(), vector<int>(capacity + 1, -1));
    return compute_optimum_knapsack(items, items.size() - 1, capacity, v);
}
#endif //EPI_17_6_H
