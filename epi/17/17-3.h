//
// Created by Li Zuwei on 10/23/16.
//

#ifndef EPI_17_3_H
#define EPI_17_3_H
#include <vector>
#include <string>

using namespace std;
// num_ways[row][col] = num_ways[row-1][col] + num_ways[row][col-1]
int compute_num_ways(int row, int col, vector<vector<int> >& num_ways) {
    if(row == 0 && col == 0)
        return 1;

    //if not populated, populate else skip
    if(num_ways[row][col] == 0) {
        //unfilled, recurse and fill
        int ways_top = row == 0 ? 0 : compute_num_ways(row-1, col, num_ways);
        int ways_left = col == 0 ? 0 : compute_num_ways(row, col-1, num_ways);
        num_ways[row][col] = ways_top + ways_left;
    }
    return num_ways[row][col];
}

int num_ways_traverse_2darray(int m, int n) {
    vector<vector<int>> num_ways(m, vector<int>(m, 0));
    return compute_num_ways(m-1, n-1, num_ways);
}
#endif //EPI_17_3_H
