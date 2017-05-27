//
// Created by Li Zuwei on 10/22/16.
//

#ifndef EPI_17_1_H
#define EPI_17_1_H
#include <vector>
using namespace std;

int num_score_combinations(int final_score, const vector<int>& play_scores) {
    vector<vector<int>> score_combinations(play_scores.size(), vector<int>(final_score + 1, 0)); // include 0 score
    for(int i = 0; i < play_scores.size(); ++i) {
        score_combinations[i][0] = 1; // 1 way to reach score of 0
        for(int j = 1; j <= final_score; ++j) {
            int without_this_play = i >= 1 ? score_combinations[i - 1][j] : 0;
            int with_this_play = j >= play_scores[i] ? score_combinations[i][j - play_scores[i]] : 0;
            score_combinations[i][j] = without_this_play + with_this_play;
        }
    }
    return score_combinations.back().back();
}
#endif //EPI_17_1_H
