//
// Created by Li Zuwei on 10/22/16.
//

#ifndef EPI_17_2_H
#define EPI_17_2_H
#include <vector>
#include <string>
using namespace std;

int compute_distance_between_prefixes(const string& a, int a_idx, const string& b, int b_idx,
                                      vector<vector<int>>& distance_between_prefixes) {
    if(a_idx < 0) {
        // we add all the b characters
        return b_idx + 1;
    }
    else if(b_idx < 0) {
        // we delete all the balance a characters
        return a_idx + 1;
    }

    // handle the case if the characters are the same
    if(a[a_idx] == b[b_idx]) {
        // just continue to compare the previous substring
        return compute_distance_between_prefixes(a, a_idx-1, b, b_idx-1, distance_between_prefixes);
    }
    else {
        // different, we will find the min of each type of change performed on the substring
        int subst_last = compute_distance_between_prefixes(a, a_idx-1, b, b_idx-1, distance_between_prefixes);
        int insert_last = compute_distance_between_prefixes(a, a_idx-1, b, b_idx, distance_between_prefixes);
        int delete_last = compute_distance_between_prefixes(a, a_idx, b, b_idx-1, distance_between_prefixes);
        distance_between_prefixes[a_idx][b_idx] = 1 + min({subst_last, insert_last, delete_last});
    }
    return distance_between_prefixes[a_idx][b_idx];
}


int levenshtein_distance(const string& a, const string& b) {
    vector<vector<int>> distance_between_prefixes(a.size(), vector<int>(b.size(), -1));
    return compute_distance_between_prefixes(a, a.size() - 1, b, b.size() - 1, distance_between_prefixes);
}

string longest_common_subsequence(const string& a, const string& b) {
    vector<vector<int>> l(a.size() + 1, vector<int>(b.size() + 1, 0)); //add 1 to handle the last characters
    for(int i = 0; i <= a.size(); ++i) {
        for( int j = 0; j <= b.size(); ++j) {
            if(i == 0 || j == 0) {
                l[i][j] = 0;
            }
            else if(a[i - 1] == b[j - 1]) {
                //similar add 1
                l[i][j] = l[i-1][j-1] + 1;
            }
            else {
                l[i][j] = max(l[i-1][j], l[i][j-1]);
            }
        }
    }

    int lcs_count = l[a.size()][b.size()];
    string lcs(lcs_count, '0');
    int a_idx = a.size();
    int b_idx = b.size();
    while(a_idx > 0 && b_idx > 0) {
        if(a[a_idx-1] == b[b_idx-1]) {
            lcs[lcs_count-1] = a[a_idx-1];
            a_idx--;
            b_idx--;
            lcs_count--;
        }
        else if(l[a_idx-1][b_idx] > l[a_idx][b_idx-1])
            a_idx--;
        else
            b_idx--;
    }
    return lcs;
}
#endif //EPI_17_2_H
